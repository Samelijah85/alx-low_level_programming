#!/bin/bash
wget -P /tmp/ https://raw.github.com/Samelijah85/alx-low_level_programming/master/0x18-dynamic_libraries/libdynamic.so
export LD_PRELOAD=/tmp/libdynamic.so
