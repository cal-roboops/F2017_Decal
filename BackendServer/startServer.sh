#!/bin/sh

# Change to server user (no password)
# Created with: adduser --no-create-home --disabled-password --force-badname uServer
su uServer

# Run command server
./server &

# Setup stream variables
roverIP=192.0.0.10
multiIP=239.255.0
multiPort=9001
vlcOptions="--sout-all --sout-keep"

# Open & broadcast stream 1
cvlc rtsp://${roverIP}:9001/ --sout "#rtp{dst=${multiIP}.1,port=${multiPort},mux=ts}" ${vlcOptions} &

# Open & broadcast stream 2
cvlc rtsp://${roverIP}:9002/ --sout "#rtp{dst=${multiIP}.2,port=${multiPort},mux=ts}" ${vlcOptions} &

# Open & broadcast stream 3
cvlc rtsp://${roverIP}:9003/ --sout "#rtp{dst=${multiIP}.3,port=${multiPort},mux=ts}" ${vlcOptions} &

# Log out of server user
exit
