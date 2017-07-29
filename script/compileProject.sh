#!/bin/sh
LD_LIBRARY_PATH="$LD_LIBRARY_PATH;/usr/local/lib"
cd $HOME/GitHub/PCMM/build && make
