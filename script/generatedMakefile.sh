#!/bin/sh
LD_LIBRARY_PATH="$LD_LIBRARY_PATH;/usr/local/lib"
ProjectDir=$1
EnableTesting=$2
if [ "$EnableTesting" == "Test"]; then
    cd $ProjectDir/build && cmake ../sourceCode -DPCMM_ENABLE_TEST=true
else
    cd $ProjectDir/build && cmake ../sourceCode
fi
