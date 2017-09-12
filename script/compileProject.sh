#!/bin/sh
LD_LIBRARY_PATH="$LD_LIBRARY_PATH;/usr/local/lib"
ProjectDir=$1
cd $ProjectDir/build && make
