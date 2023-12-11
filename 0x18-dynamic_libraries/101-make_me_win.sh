#!/bin/bash
wget -P /tmp/ https://github.com/Samelijah85/alx-low_level_programming/master/0x18-dynamic_libraries/nrandom.so
export LD_PRELOAD=/tmp/libgiga.so
