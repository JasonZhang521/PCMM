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
    echo "-s address, server address port, for example: -s 192.168.1.135:8888"
    echo "-p path, package path, for example: -p /home/user/pcmm/"
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
        ServerIpAddressPortOpt=`echo "$ArgumentList" | grep "\-s"` 
        if [ "$ServerIpAddressPortOpt" = "" ]; then
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

    while getopts "s:p:t:h" arg
    do
        case $arg in
            s)
                ServerIpAddressPort=$OPTARG
                ServerIpAddressPortTag=true
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

checkIpAddressPort()
{
    echo $1 > /tmp/tmpIpPort
    echo $1 | grep "^[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}:[0-9]\{4,5}$" > /dev/null
    if [ $? == 1 ]; then
        echo "error format Ip address and port"
        exit 1
    else
        a=$(cut -d. -f1 /tmp/tmpIpPort)
        b=$(cut -d. -f2 /tmp/tmpIpPort)
        c=$(cut -d. -f3 /tmp/tmpIpPort)
        de=$(cut -d. -f4 /tmp/tmpIpPort)
        echo $de > /tmp/tmpIpPortEnd
        d=$(cut -d: -f1 /tmp/tmpIpPortEnd)
        e=$(cut -d: -f2 /tmp/tmpIpPortEnd)
        for no in $a $b $c $d
        do
            if [ $no -ge 255 ] || [ $no -lt 0 ]; then
                echo "error number in Ip address"
                exit 1
            fi
        done
    fi

    rm /tmp/tmpIpPort
    rm /tmp/tmpIpPortEnd
    return 0
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
        if [ $ServerIpAddressPort == "" ]; then
            echo "install client image must specific the server Ip address"
            exit 1
        else
            checkIpAddressPort $ServerIpAddressPort
        fi
    else
       if [ $ServerIpAddressPortTag == true ]; then
           echo "install server no need specific the server Ip address"
           exit 1
       fi
    fi
}

installPackage()
{
    echo "$InstallDir"
    cp -r "$PackagePath/bin" "$InstallDir"
    cp -r "$PackagePath/sbin" "$InstallDir"
    if [ $ImageType == "client" ]; then
        if [ -d "$InstallDir/config/conf.server" ]; then
            rm "$InstallDir/config/conf.server"
        fi
        echo "$ServerIpAddressPort" > "$InstallDir/config/conf.server" 
    fi
}

parseArgument $@
checkParameter
initInstallDir
installPackage
