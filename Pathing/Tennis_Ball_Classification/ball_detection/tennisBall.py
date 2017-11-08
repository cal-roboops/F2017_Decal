import cv2
import numpy as np

from os import listdir
from os.path import isfile, join

data_path = "tennis_ball_images/"
image_names = [f for f in listdir(data_path) if isfile(join(data_path, f))]

for image_name in image_names:
	img = cv2.imread(image_name)
	# img = cv2.imread('Tennis-Court-stock-800.jpg')
	# img = cv2.imread('ball2.jpg')
	green = ([0, 150, 170], [175, 255, 255])

	lower = np.array(green[0], dtype = "uint8")
	upper = np.array(green[1], dtype = "uint8")

	mask = cv2.inRange(img, lower, upper)
	output = cv2.bitwise_and(img, img, mask = mask)

	cv2.imshow("green", np.hstack([img, output]))
	cv2.waitKey(0)
	cv2.destroyAllWindows()
