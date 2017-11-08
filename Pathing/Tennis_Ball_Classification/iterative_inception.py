import classify_image as classifier

from os import listdir
from os.path import isfile, join

__MAX_IMAGES_TO_CLASSIFY = 10

data_path = "/Users/Hank/Documents/Mars Rover/ball_detection/tennis_ball_images/"
image_names = [f for f in listdir(data_path) if isfile(join(data_path, f))]

def make_absolute(file_name):
	return data_path + file_name

image_paths = map(make_absolute, image_names)

for i in range(min(__MAX_IMAGES_TO_CLASSIFY, len(image_names))):
	print("")
	print("------------------------------------------")
	print("")
	classifier.evaluate(image_paths[i])
	

# classifier.evaluate('/Users/Hank/Documents/Mars Rover/ball_detection/tennis_ball_images/n04409515_7387.JPEG')
# classifier.evaluate('/Users/Hank/Documents/Mars Rover/ball_detection/tennis_ball_images/n04409515_817.JPEG')