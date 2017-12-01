import numpy as np
import matplotlib.pyplot as plt

# import heapq


def get_cloud_risk(z_height_grid):
	if z_height_grid is None:
		row = np.linspace(0,1,1000)
		z_height_grid = np.tile(row, (1000,1)).T
	

	x_height_vel = np.diff(z_height_grid, axis=1)
	y_height_vel = np.diff(z_height_grid, axis=0)

	x_height_accel = np.diff(x_height_vel, axis=1)
	y_height_accel = np.diff(y_height_vel, axis=0)



	cloud_risk = (np.mean(x_height_vel) + np.mean(y_height_vel))**2
	 + np.mean(x_height_accel), np.mean(y_height_accel)

	 return cloud_risk

# plt.matshow(grid, cmap=plt.cm.ocean)
# plt.matshow(x_height_accel, cmap=plt.cm.ocean)
# plt.matshow(y_height_accel, cmap=plt.cm.ocean)
# plt.show()

# def path(start, end, x_max, x_min):
# 	"""
# 	start: (x,y) coord pair
# 	end:  (x,y) coord pair
# 	"""

# 	dist = lambda x, y, end_x, end_y: np.sqrt((end_x-x)**2, (end_y-y)**2)

# 	x = start[0]
# 	y = start[1]

# 	seen = np.zeros((x_max, y_max))

# 	fringe = [(x,y)]

# 	came_from = {}

# 	past_cost = np.full((x_max, y_max), np.inf)

# 	past_cost[x,y] = 0

# 	future_score = np.full((x_max, y_max), np.inf)

# 	future_score[x,y] = dist(x,y)

# 	while len(fringe) is not 0:
# 		current = heapq.heappop(fringe)


# def compute_height_accel(z_heights):
	# x_height_accel = np.diff(np.diff(z_heights, axis=1), axis=1)
	# y_height_accel = np.diff(np.diff(z_heights, axis=0), axis=0)
