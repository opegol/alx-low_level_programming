#!/bin/bash
wget -P /tmp/ https://raw.github.com./opegol/ alx-low_level_programming/0x18-dynamic_libraries/lib.so
export LD_PRELOAD=/tmp/lib.so
