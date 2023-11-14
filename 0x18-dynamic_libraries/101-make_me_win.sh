#!/bin/bash
wget -P .. https://github.com/EddV23/alx-low_level_programming/blob/master/0x18-dynamic_libraries/mywin.so
export LD_PRELOAD="$PWD/../myrand_2.so"
