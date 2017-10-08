#!/bin/sh

# Change to rover user (no password)
# Created with: adduser --no-create-home --disabled-password --force-badname uRover
su uRover

# Run command server
./roverClient &

# Setup stream variables
serverIP=127.0.0.1
vlcOptions="--sout-all --sout-keep"

# Open & broadcast stream 1
cvlc v4l2:///dev/video0 --sout "#rtp{sdp=rtsp://:9001/}" ${vlcOptions} &

# Open & broadcast stream 2
cvlc v4l2:///dev/video1 --sout "#rtp{sdp=rtsp://:9002/}" ${vlcOptions} &

# Open & broadcast stream 3
cvlc v4l2:///dev/video3 --sout "#rtp{sdp=rtsp://:9001/}" ${vlcOptions} &

# Log out of rover user
exit
