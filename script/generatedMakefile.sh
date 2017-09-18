#!/bin/sh
LD_LIBRARY_PATH="$LD_LIBRARY_PATH;/usr/local/lib"
ProjectDir=$1
BuildDir="$ProjectDir/build"
if [ ! -d $BuildDir ]; then
    mkdir "$BuildDir"
fi
EnableTesting=$2
if [ "$EnableTesting" == "Test" ]; then
    cd $BuildDir && cmake ../sourceCode -DPCMM_ENABLE_TEST=TRUE
else
    cd $BuildDir && cmake ../sourceCode -DPCMM_ENABLE_TEST=FALSE
fi
