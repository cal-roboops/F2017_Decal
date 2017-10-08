#!/bin/sh

# Run command server
./server &

# Open & broadcast stream 1
sudo -u uvlc cvlc file:///mnt/h/MITCHELL\ STUFF\ 2/Movies,\ Shows,\ Books/Movies/Mad\ Max\ Fury\ Road.mp4 --sout "#rtp{dst=239.255.0.1,port=9001,mux=ts}" --sout-all --sout-keep &

# Open & broadcast stream 2
sudo -u uvlc cvlc file:///mnt/h/MITCHELL\ STUFF\ 2/Movies,\ Shows,\ Books/Movies/Mad\ Max\ Fury\ Road.mp4 --sout "#rtp{dst=239.255.0.2,port=9001,mux=ts}" --sout-all --sout-keep &

# Open & broadcast stream 3
sudo -u uvlc cvlc file:///mnt/h/MITCHELL\ STUFF\ 2/Movies,\ Shows,\ Books/Movies/Mad\ Max\ Fury\ Road.mp4 --sout "#rtp{dst=239.255.0.3,port=9001,mux=ts}" --sout-all --sout-keep &
