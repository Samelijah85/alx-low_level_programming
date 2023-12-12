#!/bin/bash
wget -p .. https://raw.githubusercontent.com/Samelijah85/alx-low_level_programming/master/0x18-dynamic_libraries/libdynamic.so 
export LD_PRELOAD="$PWD/../libdyamic.so"
