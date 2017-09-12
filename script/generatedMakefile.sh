#!/bin/sh
LD_LIBRARY_PATH="$LD_LIBRARY_PATH;/usr/local/lib"
ProjectDir=`echo $(cd "$(dirname "$0")/.."; pwd)`
cd $ProjectDir/build && cmake ../sourceCode
