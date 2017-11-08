#!/bin/bash
x=0
for i in $( ls tennis_ball_images/); do
	if [ $x -lt 4 ]
	then
		let "x++"
		echo $(python /Users/Hank/Documents/Mars\ Rover/models/tutorials/image/imagenet/classify_image.py --image_name tennis_ball_images/$i)
		echo "--------"
	fi
done