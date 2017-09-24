#!/bin/sh

pwd

ServerIpAddressPort=""
ServerIpAddressPortTag=false
PackagePath=""
ImageType=""
InstallDir=""

initInstallDir()
{
    echo "initialize Install Dir"
    RootDir=/opt/HongClusterMgt
    if [ ! -d "$RootDir" ]; then
        mkdir "$RootDir"
    fi
    if [ ! -d "$RootDir/config" ]; then
        mkdir "$RootDir/config"
    fi
    if [ ! -d "$RootDir/log" ]; then
        mkdir "$RootDir/log"
    fi
    if [ ! -d "$RootDir/temp" ]; then
        mkdir $RootDir/temp
    fi
    InstallDir="$RootDir"
    echo "initialize Install Dir completed"
}

help()
{
    echo "-p path, package path, for example: -p /home/user/pcmm/"
}

parseArgument()
{
    ArgumentList=$@
    ArgumentNum=$#

    if [ "$ArgumentNum" -eq 0 ]; then
        echo "error arguments, usage as following:"
        help
        exit 1
    fi
    HelpOpt=`echo "$ArgumentList" | grep "\-h"`
    if [ "$HelpOpt" == "" ]; then

        PackagePathOpt=`echo $ArgumentList | grep "\-p"`
        if [ "$PackagePathOpt" == "" ]; then
            echo "should have package path, usage as following:"
            help
            exit 1
        fi
    fi

    while getopts "p:h" arg
    do
        case $arg in
            p)
                PackagePath=$OPTARG
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


checkPackagePath()
{
    if [ ! -d "$PackagePath" ]; then
        echo "package $PackagePath is not exsisted!"
        exit 1
    fi
    if [ ! -d "$PackagePath/bin" ]; then
        echo "$PackagePath/bin is not exsisted!"
        exit 1
    fi
    if [ ! -d "$PackagePath/sbin" ]; then
        echo "$PackagePath/sbin is not exsisted!"
        exit 1
    fi
}


installPackage()
{
    echo "$InstallDir"
    cp -r "$PackagePath/bin" "$InstallDir"
    cp -r "$PackagePath/sbin" "$InstallDir"
	UiServer="$InstallDir/config/conf.ui.server"
	NodeServer="$InstallDir/config/conf.node.server"
	if [ ! -f "$UiServer" ]; then
		touch "$UiServer"
    fi
	if [ ! -f "$NodeServer" ]; then
		touch "$NodeServer"
    fi
}

parseArgument $@
initInstallDir
installPackage
