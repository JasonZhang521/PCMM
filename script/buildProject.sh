#!/bin/sh

EnableTesting=disable

help()
{
	echo "usage:"
    echo "    -t: enable testing"
    exit 1
}

parseArgument()
{
    while getopts "th" arg
    do
        case $arg in
            t)
                EnableTesting=enable
                ;;
            h)
                help
                ;;
            ?)
                echo "unkonw argument, usage as following:"
                help
                exit 1
                ;;
            esac
    done
}

parseArgument $@
echo "$EnableTesting ---"
ProjectDir=`echo $(cd "$(dirname "$0")/.."; pwd)`

if [ "$EnableTesting" == "enable" ]; then
    $ProjectDir/script/generatedMakefile.sh "$ProjectDir" "Test" 
else
    $ProjectDir/script/generatedMakefile.sh "$ProjectDir"
fi

$ProjectDir/script/compileProject.sh "$ProjectDir"
