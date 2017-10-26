import urllib.parse
import urllib.request
import cv2
import numpy as np
import math
import json
import os
from heapq import *

MAPS_BASE_URL = 'https://maps.googleapis.com/maps/api/staticmap?'
ELEVATION_BASE_URL = 'https://maps.googleapis.com/maps/api/elevation/json?'
MAPS_KEY = 'AIzaSyACAgW0t93bEbyJn3dWNwSLcjXzY3O8DiY'

# lat lon of Mars Desert Research Center Hankville, UT
LAT = 38.406529
LON = -110.791916
IMG_SIZE = 640
ZOOM = 19
MAPTYPE = 'satellite'
# KEEP THIS 1 FOR NOW CHANGING CAN BREAK COORDINATE CALCULATIONS
SCALE = 1

# contains lat, lon, elevation, isBlocked for each coordinate
MAP_DATA = np.zeros((IMG_SIZE, IMG_SIZE, 4), dtype=np.float64)

BASE_ELEVATION = 1371.5
START = (38.406421, -110.791767)
END = (38.407016, -110.792077)

# makes request to google maps api
def map_request(size, lat, lon, zoom, maptype, scale):
    params = urllib.parse.urlencode({
        'size' : str(size) + 'x' + str(size),
        'center' : str(lat) + ',' + str(lon),
        'zoom' : str(zoom),
        'maptype' : maptype,
        'scale' : str(scale),
        'key' : MAPS_KEY
    })

    return urllib.request.urlopen(MAPS_BASE_URL + params).read()

# makes request to google elevation api (resolution is approx 9m at competition location)
def elevation_request(lat, lon):
    params = urllib.parse.urlencode({
        'locations' : str(lat) + ',' + str(lon),
        'key' : MAPS_KEY
    })

    return json.loads(urllib.request.urlopen(ELEVATION_BASE_URL + params).read().decode('utf-8'))

# caclulates scale of map at current lat, lon, and zoom level
def calc_scale(lat, lon, zoom):
    # from https://gis.stackexchange.com/questions/7430/what-ratio-scales-do-google-maps-zoom-levels-correspond-to
    m_per_pixel = 156543.03392 * math.cos(math.radians(lat)) / (2 ** zoom)
    print(str(m_per_pixel) + ' meters / pixel')

    # from https://en.wikipedia.org/wiki/Geographic_coordinate_system (accurate to cm)
    m_per_deg_lat = 111132.92 - 559.82 * math.cos(math.radians(2 * lat)) + 1.175 * math.cos(math.radians(4 * lat)) + -0.0023 * math.cos(math.radians(6 * lat))
    m_per_deg_lon = 111412.84 * math.cos(math.radians(lat)) - 93.5 * math.cos(math.radians(3 * lat)) + 0.118 * math.cos(math.radians(5 * lat))

    lat_per_pixel = (1 / m_per_deg_lat) * m_per_pixel
    lon_per_pixel = (1 / m_per_deg_lon) * m_per_pixel
    print(str(lat_per_pixel) + ' deg lat / pixel')
    print(str(lon_per_pixel) + ' deg lon / pixel')

    return (lat_per_pixel, lon_per_pixel)

# returns gps coordinates (lat, lon) of each pixel (row, col)
def calc_cordinates(map_data, size, lat, lon, zoom):
    lat_per_pixel, lon_per_pixel = calc_scale(lat, lon, zoom)
    center = size / 2

    for i in range(size):
        for j in range(size):
            # set lat
            map_data[i][j][0] = lat - ((i - center) * lat_per_pixel)
            # set lon
            map_data[i][j][1] = lon + ((j - center) * lon_per_pixel)
    
    return map_data

# DON'T CALL THIS REPEATEDLY (USES A LOT OF API CALLS)
# TODO pass in data as locations array to minimize num of calls
# calculates the elevation of each pixel
def calc_elevation(map_data, size):
    # increasing this increases resolution of data but also increases number of api calls
    # at zoom 19, 20 blocks gives enough resolution
    # TODO set this dynamically using m_per_pixel
    num_blocks = 25
    block_size = size // num_blocks
    elev_data = np.zeros((num_blocks, num_blocks), dtype=np.float64)
    
    for i in range(num_blocks):
        for j in range(num_blocks):
            x = i * block_size
            y = j * block_size
            elevation = elevation_request(map_data[x][y][0], map_data[x][y][1])
            elev_data[i][j] = elevation['results'][0]['elevation']
            print(elev_data[i][j])

    for i in range(size):
        for j in range(size):
            x = min((i // block_size), num_blocks - 1)
            y = min((j // block_size), num_blocks - 1)
            map_data[i][j][2] = elev_data[x][y]

    return map_data

# calculates significant changes in elevation and marks those coordinates
def calc_drops(map_data, size):
    for i in range(size):
        for j in range(size):
            if abs(BASE_ELEVATION - map_data[i][j][2]) > 2:
                map_data[i][j][3] = 1
    return map_data

# returns x, y such that map_data[x][y] is closest to val
def find_nearest(map_data, val, size):
    x_val, y_val = val
    min_val = float('inf')
    for i in range(size):
        for j in range(size):
            cur_val = abs(map_data[i][j][0] - x_val) + abs(map_data[i][j][1] - y_val)
            if cur_val < min_val:
                min_val = cur_val
                x, y = i, j
    return x, y

# finds optimal path using A* and changes in elevation as obstacles
def find_path(map_data, size, start_gps, end_gps):
    start = find_nearest(map_data, start_gps, size)
    # print(start)
    goal = find_nearest(map_data, end_gps, size)
    # print(goal)

    obstacle_map = map_data[:,:,3]

    path = astar(obstacle_map, start, goal)
    return list(reversed(path)) if path else None

def heuristic(a, b):
    # euclidian distance
    return (b[0] - a[0]) ** 2 + (b[1] - a[1]) ** 2

# source: http://code.activestate.com/recipes/578919-python-a-pathfinding-with-binary-heap/
def astar(array, start, goal):
    # supports quad-directional movement
    neighbors = [(0,1),(0,-1),(1,0),(-1,0),(1,1),(1,-1),(-1,1),(-1,-1)]

    close_set = set()
    came_from = {}
    gscore = {start:0}
    fscore = {start:heuristic(start, goal)}
    oheap = []

    heappush(oheap, (fscore[start], start))
    
    while oheap:
        current = heappop(oheap)[1]
        # if at goal return path used to get here
        if current == goal:
            data = []
            while current in came_from:
                data.append(current)
                current = came_from[current]
            return data

        close_set.add(current)
        for i, j in neighbors:
            neighbor = current[0] + i, current[1] + j            
            tentative_g_score = gscore[current] + heuristic(current, neighbor)
            if 0 <= neighbor[0] < array.shape[0]:
                if 0 <= neighbor[1] < array.shape[1]:                
                    if array[neighbor[0]][neighbor[1]] == 1:
                        continue
                else:
                    # array bound y walls
                    continue
            else:
                # array bound x walls
                continue
                
            if neighbor in close_set and tentative_g_score >= gscore.get(neighbor, 0):
                continue
                
            if  tentative_g_score < gscore.get(neighbor, 0) or neighbor not in [i[1]for i in oheap]:
                came_from[neighbor] = current
                gscore[neighbor] = tentative_g_score
                fscore[neighbor] = tentative_g_score + heuristic(neighbor, goal)
                heappush(oheap, (fscore[neighbor], neighbor))
                
    return False

def mouse_callback(event, x, y, flags, params):
    if event == cv2.EVENT_LBUTTONDOWN:
        print(MAP_DATA[y][x])
        print(elevation_request(MAP_DATA[y][x][0], MAP_DATA[y][x][1])['results'][0]['elevation'])


map_response = map_request(IMG_SIZE, LAT, LON, ZOOM, MAPTYPE, SCALE)
map_bytes = np.fromstring(map_response, np.uint8)
map_img = cv2.imdecode(map_bytes, cv2.IMREAD_UNCHANGED)

file_name = 'map_data_' + str(LAT) + ',' + str(LON) + '_' + str(IMG_SIZE) + '_' + str(ZOOM) + '.npy'
# TODO check based on location of map_pathing.py
if os.path.isfile(file_name ):
    calc_scale(LAT, LON, ZOOM)
    MAP_DATA = np.load(file_name)
    MAP_DATA = calc_drops(MAP_DATA, IMG_SIZE)
    np.save(file_name, MAP_DATA)
else:
    MAP_DATA = calc_cordinates(MAP_DATA, IMG_SIZE, LAT, LON, ZOOM)
    MAP_DATA = calc_elevation(MAP_DATA, IMG_SIZE)
    MAP_DATA = calc_drops(MAP_DATA, IMG_SIZE)
    np.save(file_name, MAP_DATA)

PATH = find_path(MAP_DATA, IMG_SIZE, START, END)
if PATH:
    for i, j in PATH:
        map_img[i][j] = [255,255,255]
        # print((i,j))
else:
    print('NO PATH FOUND')

cv2.namedWindow('map', cv2.WINDOW_NORMAL)
cv2.resizeWindow('map', IMG_SIZE, IMG_SIZE)
cv2.setMouseCallback('map', mouse_callback)
cv2.imshow('map', map_img)
cv2.waitKey(0)
cv2.destroyAllWindows()