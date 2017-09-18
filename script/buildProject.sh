#!/bin/sh

EnableTesting=false

help()
{
    echo "-t: enable testing"
}

parseArgument()
{
    while getopts "th" arg
    do
        case $arg in
            t)
                EnableTesting=true
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

ProjectDir=`echo $(cd "$(dirname "$0")/.."; pwd)`

if [ EnableTesting -eq true ]; then
    $ProjectDir/script/generatedMakefile.sh "$ProjectDir" "Test" 
else
    $ProjectDir/script/generatedMakefile.sh "$ProjectDir"
fi

$ProjectDir/script/compileProject.sh "$ProjectDir"
