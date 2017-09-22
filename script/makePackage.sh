#!/bin/sh
ProjectDir=$2
if [ "$ProjectDir" == "" ]; then
    ProjectDir=`echo $(cd "$(dirname "$0")/.."; pwd)`
fi

BuildDir=$1
if [ "$BuildDir" == "" ]; then
    BuildDir="$ProjectDir/build/Package"
fi

if [ ! -d "$BuildDir" ]; then
    mkdir "$BuildDir"
fi 

ClientImage=$ProjectDir/build/SystemMonitor/ComputerNodeMonitor.elf
ServerImage=$ProjectDir/build/ClusterManagement/ClusterNodesControl.elf
TempDir=/tmp/HongClusterMgt
if [ ! -d "$TempDir" ]; then
    mkdir "$TempDir"
else
    rm -rf "$TempDir/*"
fi

GccDir=`which gcc`
LibStd6Dir="${GccDir%/*/*}/lib64/"
LibStd6Link="${GccDir%/*/*}/lib64/libstdc++.so.6"
LibStd6LinkInfo=`ls -l $LibStd6Link`
LibStd6Name=`echo $LibStd6LinkInfo | awk '{print $11}'`					 
LibStd6="$LibStd6Dir$LibStd6Name"

mkdir "$TempDir/bin"
mkdir "$TempDir/script"
mkdir "$TempDir/sbin"

cp "$ClientImage" "$TempDir/bin"
cp "$ServerImage" "$TempDir/bin"
cp "$LibStd6" "$TempDir/sbin/libstdc++.so.6"
cp "$ProjectDir/script/installPackage.sh" "$TempDir/script"

grep "Version" $ProjectDir/sourceCode/Version/HongClusterMgt_Verstion.h > /tmp/tmpvesion
Version=$(cut -d\" -f2 /tmp/tmpvesion)
rm "/tmp/tmpvesion"

PackageName="$BuildDir/HongClusterMgt.$Version.tar.gz"
cd $TempDir && tar -czvf  $PackageName * 

rm -rf "$TempDir"
