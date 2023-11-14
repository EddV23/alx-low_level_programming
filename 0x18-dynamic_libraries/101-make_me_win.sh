#!/bin/bash
wget -P /tmp https://github.com/EddV23/alx-low_level_programming/raw/master/0x18-dynamic_libraries/mywin_2.so.so
export LD_PRELOAD=/tmp/mywin_2.so
