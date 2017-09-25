#!/bin/sh

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
    echo "   package path is the bin files director or the package tar.gz file."
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

checkPackageType()
{
    if [ -f "$PackagePath" ]; then
        TarGzExist=`echo "$PackagePath" | grep '.*HongClusterMgt\.[0-9]\.[0-9]\.tar\.gz$'`
        if [ -z "$TarGzExist" ]; then
            return 0
        else
            return 1
        fi
    else
        if [ -d "$PackagePath" ]; then
            return 2
        fi
    fi
    return 0
}

checkPackagePathDir()
{
    local PackageFilesPath=$1
    if [ ! -d "$PackageFilesPath" ]; then
        echo "package $PackageFilesPath is not exsisted!"
        exit 1
    fi

    if [ ! -d "$PackageFilesPath/bin" ]; then
        echo "$PackageFilesPath/bin is not existed!"
        exit 1
    fi
    
    if [ ! -f "$PackageFilesPath/bin/ClusterNodesControl.elf" ]; then
        echo "$PackageFilesPath/bin/ClusterNodesControl.elf is not existed!"
        exit 1
    fi

    if [ ! -f "$PackageFilesPath/bin/ComputerNodeMonitor.elf" ]; then
        echo "$PackageFilesPath/bin/ComputerNodeMonitor.elf is not existed!"
        exit 1
    fi

    if [ ! -d "$PackageFilesPath/sbin" ]; then
        echo "$PackageFilesPath/sbin is not exsisted!"
        exit 1
    fi
}

installPackageFromTarGz()
{
    TmpDir="/tmp/.HongInstall_qwerty_temp"
    if [ ! -d "$TmpDir" ]; then
        mkdir "$TmpDir"
    fi
    tar -xzf "$PackagePath" -C "$TmpDir"
    installPackageFromDir "$TmpDir"
    rm -rf "$TmpDir"
}

installPackageFromDir()
{
    local PackageFilesPath=$1
    checkPackagePathDir $PackageFilesPath
    echo "install bin!"
    cp -r "$PackageFilesPath/bin" "$InstallDir"
    echo "install sbin"
    cp -r "$PackageFilesPath/sbin" "$InstallDir"
    echo "install config"
    UiServer="$InstallDir/config/conf.ui.server"
    NodeServer="$InstallDir/config/conf.node.server"
    if [ ! -f "$UiServer" ]; then
	touch "$UiServer"
    fi
    if [ ! -f "$NodeServer" ]; then
	touch "$NodeServer"
    fi
}

installPackage()
{
    checkPackageType
    Type=$?
    if [ $Type -eq 1 ]; then
        installPackageFromTarGz $PackagePath
    elif [ $Type -eq 2 ]; then
        installPackageFromDir $PackagePath
    else
        echo "error usage command!"
        help
        exit 1
    fi
    echo "installation completed"
}

parseArgument $@
initInstallDir
installPackage
