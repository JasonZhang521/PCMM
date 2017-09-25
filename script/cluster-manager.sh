#!/bin/sh

function checkIpPort()
{
    echo $1 > /tmp/tmpIpPort
    echo $1 | grep "^[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}:[0-9]\{4,5}$" > /dev/null
    if [ $? == 1 ]; then
        echo "error format ip and port"
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
                echo "error Ip address"
                exit 1
            fi
        done
    fi

    rm /tmp/tmpIpPort
    rm /tmp/tmpIpPortEnd
}

function cluster-manager_add_server()
{
	local ipPort=$1
    local serverConfigFile=$2
	if [ ! -f $serverConfigFile ]; then
		touch $serverConfigFile
	fi
	local findRet=grep "$ipPort" "$serverConfigFile"
	if [ -z $findRet ];then
	    echo "$ipPort" >> "$serverConfigFile"
	else
		echo "server $ipPort already exist in $serverConfigFile!"
	fi
}

function cluster-manager_delete_server()
{
	local ipPort=$1
    local serverConfigFile=$2
	if [ -f $serverConfigFile ]; then
		sed -i '/"$ipPort"/d' "$serverConfigFile"
	fi
}

function cluster-manager_list_server()
{
    local serverConfigFile=$1
	if [ -f $serverConfigFile ]; then
		cat "$serverConfigFile"
	fi
}

function cluster-manager_add()
{
    local cmd=$1
	local ipPort=$2
	checkIpPort $ipPort
    case "$cmd" in
	"ui-server")
	    cluster-manager_add_server $ipPort "/opt/HongClusterMgt/config/conf.ui.server"
	    ;;
	"node-server")
	    cluster-manager_add_server $ipPort "/opt/HongClusterMgt/config/conf.node.server"
		;;
	esac
}

function cluster-manager_delete()
{
    local cmd=$1
	local ipPort=$2
	checkIpPort $ipPort
    case "$cmd" in
	"ui-server")
	    cluster-manager_delete_server $ipPort "/opt/HongClusterMgt/config/conf.ui.server"
	    ;;
	"node-server")
	    cluster-manager_delete_server $ipPort "/opt/HongClusterMgt/config/conf.node.server"
		;;
	esac
}

function cluster-manager_list()
{
    local cmd=$1
    case "$cmd" in
	"ui-server")
	    cluster-manager_list_server "/opt/HongClusterMgt/config/conf.ui.server"
	    ;;
	"node-server")
	    cluster-manager_list_server "/opt/HongClusterMgt/config/conf.node.server"
		;;
	esac
}

function cluster-manager()
{
    local cmd=$1
	shift
    case "$cmd" in
	"add")
	    cluster-manager_add $@
		;;
	"delete")
		cluster-manager_delete $@
		;;
	"list")
	    cluster-manager_list $@
		;;
	"start")
	    cluster-manager_start $@
		;;
	"stop")
	    cluster-manager_stop $@
		;;
	"restart")
	    cluster-manager_restart $@
		;;
	"trace-debug")
	    cluster-manager_trace-debug $@
		;;
	esac
}
