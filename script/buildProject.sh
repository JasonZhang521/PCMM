#!/bin/sh
ProjectDir=`echo $(cd "$(dirname "$0")/.."; pwd)`
$ProjectDir/script/generatedMakefile.sh
$ProjectDir/script/compileProject.sh
