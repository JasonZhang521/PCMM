#!/bin/sh

ServerIpAddress=""
PackagePath=""
ImageType=""

initInstallDir()
{
    rootDir=/opt/HongClusterMgt
    if [ ! -d "$rootDir"]; then
        mkdir $rootDir
    fi
    if [ ! -d "$rootDir/network"]; then
        mkdir $rootDir/network
    fi
    if [ ! -d "$rootDir/log"]; then
        mkdir $rootDir/log
    fi
    if [ ! -d "$rootDir/temp"]; then
        mkdir $rootDir/temp
    fi
}

help()
{
    echo "-a address, server address, for example: -a 192.168.1.135"
    echo "-p path, package path, for example: -p /home/user/pcmm.tar.gz"
    echo "-t type, image type, type = [server, client],  for example: -t server"
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
        ServerIpAddressOpt=`echo "$ArgumentList" | grep "\-a"` 
        if [ "$ServerIpAddressOpt" = "" ]; then
            echo "should have server Ip address, usage as following:"
            help
            exit 1
        fi

        PackagePathOpt=`echo $ArgumentList | grep "\-p"`
        if [ "$PackagePathOpt" == "" ]; then
            echo "should have package path, usage as following:"
            help
            exit 1
        fi

        ImageTypeOpt=`echo $ArgumentList | grep "\-t"`
        if [ "$ImageTypeOpt" == "" ]; then
            echo "should have image type, usage as following:"
            help
            exit 1
        fi
    fi

    while getopts "a:p:t:h" arg
    do
        case $arg in
            a)
                ServerIpAddress=$OPTARG
				if [ "$ServerIpAddress" == "" ]; then
					echo "should have Ip address after -a"
				    exit 1
			    fi
                ;;
            p)
                PackagePath=$OPTARG
                if [ "$PackagePath" == "" ]; then
					echo "should have package path after -p"
				    exit 1
				fi
                if [ ! -f "$PackagePath"]; then
                    echo "package $PackagePath is not exsisted!"
                    exit 1
                fi
                ;;
            t)
                ImageType=$OPTARG
                if [ "$ImageType" != "server" ] && [ "$ImageType" != "client" ]; then
                    echo "image type error,  only support 'server' or 'client'!"
                    exit 1
                fi
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
