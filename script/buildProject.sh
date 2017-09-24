#!/bin/sh

EnableTesting=disable
BuildDir=""
help()
{
	echo "usage:"
    echo "    -t: enable testing"
    exit 1
}

parseArgument()
{
    while getopts "tho:" arg
    do
        case $arg in
            t)
                EnableTesting=enable
                ;;
	        o)  BuildDir=$OPTARG
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

if [ "$BuildDir" == "" ]; then
    BuildDir="$ProjectDir/build/Package"
fi

$ProjectDir/script/makePackage.sh "$BuildDir" "$ProjectDir"

