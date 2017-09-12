#!/bin/sh

ServerIpAddress=""
ServerIpAddressTag=false
PackagePath=""
ImageType=""

initInstallDir()
{
    rootDir=/opt/HongClusterMgt
    if [ ! -d "$rootDir" ]; then
        mkdir $rootDir
    fi
    if [ ! -d "$rootDir/network" ]; then
        mkdir $rootDir/network
    fi
    if [ ! -d "$rootDir/log" ]; then
        mkdir $rootDir/log
    fi
    if [ ! -d "$rootDir/temp" ]; then
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
                ServerIpAddressTag=true
                ;;
            p)
                PackagePath=$OPTARG
                ;;
            t)
                ImageType=$OPTARG
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

checkIpAddress()
{
    echo $1 > /tmp/tmpip
    echo $1 | grep "^[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}$" > /dev/null
    if [ $? == 1 ]; then
        echo "error format Ip address"
        exit 1
    else
        a=$(cut -d. -f1 /tmp/tmpip)
        b=$(cut -d. -f2 /tmp/tmpip)
        c=$(cut -d. -f3 /tmp/tmpip)
        d=$(cut -d. -f4 /tmp/tmpip)

        for no in $a $b $c $d
        do
            if [ $no -ge 255 ] || [ $no -le 0 ]; then
                echo "error number in Ip address"
                exit 1
            fi
        done
    fi
    return 0
}

checkPackagePath()
{
    if [ ! -f "$PackagePath" ]; then
        echo "package $PackagePath is not exsisted!"
        exit 1
    fi
}

checkImageType()
{
    if [ "$ImageType" != "server" ] && [ "$ImageType" != "client" ]; then
        echo "image type error,  only support 'server' or 'client'!"
        exit 1
    fi
}


checkParameter()
{
    checkPackagePath
    checkImageType
    if [ $ImageType == "client" ]; then
        if [ $ServerIpAddress == "" ]; then
            echo "install client image must specific the server Ip address"
            exit 1
        else
            checkIpAddress $ServerIpAddress
        fi
    else
       if [ $ServerIpAddressTag == true ]; then
           echo "install server no need specific the server Ip address"
           exit 1
       fi
    fi
}

parseArgument $@
checkParameter
