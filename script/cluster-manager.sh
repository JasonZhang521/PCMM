#!/bin/sh

NumOfClientInstance=1
NumOfServerInstance=1

function helpIpPort()
{
    echo "ip port should format as: a.b.c.d:port"
    echo "    a, b, c, d should valid interger"
    echo "    port should a 4 or 5 interger"
}

function checkIpPort()
{
    echo $1 > /tmp/tmpIpPort
    echo $1 | grep "^[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}:[0-9]\{4,5\}$" > /dev/null
    if [ $? -eq 1 ]; then
        echo "error format ip and port"
        helpIpPort
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
                helpIpPort
                exit 1
            fi
        done
    fi

    rm /tmp/tmpIpPort
    rm /tmp/tmpIpPortEnd
}

function cluster_manager_add_server()
{
	local ipPort=$1
        local serverConfigFile=$2
	if [ ! -f $serverConfigFile ]; then
		touch $serverConfigFile
	fi
	local findRet=`grep "$ipPort" "$serverConfigFile"`
	if [ -z $findRet ];then
	    echo "$ipPort" >> "$serverConfigFile"
	else
		echo "server $ipPort already exist in $serverConfigFile!"
	fi
}

function cluster_manager_delete_server()
{
	local ipPort=$1
        local serverConfigFile=$2
	if [ -f $serverConfigFile ]; then
		sed -i "/$ipPort/d" "$serverConfigFile"
	fi
}

function cluster_manager_list_server()
{
    local serverConfigFile=$1
	if [ -f $serverConfigFile ]; then
		cat "$serverConfigFile"
	fi
}

function cluster_manager_add()
{
    local cmd=$1
	local ipPort=$2
	checkIpPort $ipPort
    case "$cmd" in
	"ui-server")
	    cluster_manager_add_server $ipPort "/opt/HongClusterMgt/config/conf.ui.server"
	    ;;
	"node-server")
	    cluster_manager_add_server $ipPort "/opt/HongClusterMgt/config/conf.node.server"
		;;
	*)
		echo "error usage command!"
		exit 1
	esac
}

function cluster_manager_delete()
{
    local cmd=$1
	local ipPort=$2
	checkIpPort $ipPort
    case "$cmd" in
	"ui-server")
	    cluster_manager_delete_server $ipPort "/opt/HongClusterMgt/config/conf.ui.server"
	    ;;
	"node-server")
	    cluster_manager_delete_server $ipPort "/opt/HongClusterMgt/config/conf.node.server"
		;;
	*)
		echo "error usage command!"
		exit 1
	esac
}

function cluster_manager_list()
{
    local cmd=$1
    case "$cmd" in
	"ui-server")
	    cluster_manager_list_server "/opt/HongClusterMgt/config/conf.ui.server"
	    ;;
	"node-server")
	    cluster_manager_list_server "/opt/HongClusterMgt/config/conf.node.server"
		;;
	*)
		echo "error usage command!"
		exit 1
	esac
}

function cluster_manager_check_process_manager_process()
{
	local Ret=`ps -ef | grep "ProcessManagement.elf" | grep -v "grep ProcessManagement.elf" | awk '{print $2}'`
    if [ -z "$Ret" ]; then
		echo "0"
	else
		echo "$Ret"
	fi
}

function cluster_manager_check_node_client_process()
{
	local Ret=`ps -ef | grep "ComputerNodeMonitor.elf" | grep -v "grep ComputerNodeMonitor.elf" | awk '{print $2}'`
    if [ -z "$Ret" ]; then
		echo "0"
	else
		echo "$Ret"
	fi
}

function cluster_manager_start_node_client()
{
	local Ret=`cluster_manager_check_process_manager_process`
	if [ $Ret -eq 0 ]; then
		/opt/HongClusterMgt/bin/ProcessManagement.elf  /opt/HongClusterMgt/bin/ComputerNodeMonitor.elf $NumOfClientInstance &
	else
		echo "the node client has been already started! process id $Ret"
	fi
}

function cluster_manager_check_server_process()
{
	local Ret=`ps -ef | grep "ClusterNodesControl.elf" | grep -v "grep ClusterNodesControl.elf" | awk '{print $2}'`
    if [ -z "$Ret" ]; then
		echo "0"
	else
		echo "$Ret"
	fi
}


function cluster_manager_start_server()
{
	local Ret=`cluster_manager_check_process_manager_process`
	if [ $Ret -eq 0 ]; then
		/opt/HongClusterMgt/bin/ProcessManagement.elf /opt/HongClusterMgt/bin/ClusterNodesControl.elf $NumOfServerInstance &
	else
		echo "the server has been already started! process id $Ret"
	fi
}

function cluster_manager_start()
{
    local cmd=$1
    case "$cmd" in
	"node-client")
	    cluster_manager_start_node_client
		;;
	"server")
		cluster_manager_start_server
		;;
	*)
		echo "error usage command!"
		exit 1
	esac
}

function cluster_manager_stop_node_client()
{
    local Ret=`cluster_manager_check_node_client_process`
	if [ $Ret -eq 0 ]; then
		echo "the node client has been already stopped"
	else
		kill -9 "$Ret"
    fi
}

function cluster_manager_stop_server()
{
    local Ret=`cluster_manager_check_server_process`
	if [ $Ret -eq 0 ]; then
		echo "the server has been already stopped"
	else
		kill -9 "$Ret"
    fi
}

function cluster_manager_stop()
{
    local cmd=$1
    case "$cmd" in
	"node-client")
	    cluster_manager_stop_node_client
		;;
	"server")
		cluster_manager_stop_server
		;;
	*)
		echo "error usage command!"
		exit 1
	esac
}

function cluster_manager_restart_node_client()
{
	cluster_manager_stop_node_client
	cluster_manager_start_node_client
}

function cluster_manager_restart_server()
{
	cluster_manager_stop_server
	cluster_manager_start_server
}

function cluster_manager_restart()
{
    local cmd=$1
    case "$cmd" in
	"node-client")
	    cluster_manager_restart_node_client
		;;
	"server")
		cluster_manager_restart_server
		;;
	*)
		echo "error usage command!"
		exit 1
	esac
}

function cluster_manager_help()
{
	echo "cluster-manager command usage document:"
	echo "cluster-manager add (ui-server | node-server) IP:PORT"
	echo "                configure a (ui-server | node-server) address"
	echo "                computer node client will using the node-server address to connect the control server"
	echo "                control server will listen on the ui-server address for the ui-client connection"
	echo "                                    listen on the node-server address for the node-client connection"
	echo "cluster-manager delete (ui-server | node-server) IP:PORT"
	echo "                delete a (ui-server | node-server) address, refer to the [add] command"
	echo "cluster-manager list (ui-server | node-server)"
	echo "                list the configured address for (ui-server | node-server)"
	echo "cluster-manager start (node-client | server)"
	echo "                start the (node client | control server) service"
	echo "cluster-manager stop (node-client | server)"
	echo "                stop the (node client | control server) service"
	echo "cluster-manager restart (node-client | server)"
	echo "                restart the (node client | control server) service"
	echo "cluster-manager trace-debug"
	echo "                not completed yet!!!"
}

function cluster_manager()
{
    local cmd=$1
	shift
    case "$cmd" in
	"add")
	    cluster_manager_add $@
		;;
	"delete")
		cluster_manager_delete $@
		;;
	"list")
	    cluster_manager_list $@
		;;
	"start")
	    cluster_manager_start $@
		;;
	"stop")
	    cluster_manager_stop $@
		;;
	"restart")
	    cluster_manager_restart $@
		;;
	"trace-debug")
	    cluster_manager_trace-debug $@
		;;
	"help")
	    cluster_manager_help
		;;
	*)
		echo "error usage cmmand!"
	    cluster_manager_help
		exit 1;
	esac
}

cluster_manager $@
