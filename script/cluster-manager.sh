function __cmd_Hub()
{
    case $COMP_CWORD in
    0)
        ;;
    1)
        eval __cmd_${COMP_WORDS[0]}
        ;;
    2|*)
        eval __cmd_${COMP_WORDS[1]}
        ;;
    esac
}

function __cmd__cluster-manager__add__ui-server()
{
	echo "test"
}

function __cmd__cluster-manager__add__node-server()
{
	echo "test"
}

function __cmd__cluster-manager__add()
{
    local cur=${COMP_WORDS[COMP_CWORD]}
    COMPREPLY=( $(compgen -W "ui-server node-server" -- $cur) )
}

#complete -F __cmd__cluster-manager__add cluster-manager add

function __cmd__cluster-manager__delete()
{
	echo "test"
}

function __cmd__cluster-manager__list()
{
	echo "test"
}

function __cmd__cluster-manager__start()
{
	echo "test"
}

function __cmd__cluster-manager__stop()
{
	echo "test"
}

function __cmd__cluster-manager__restart()
{
	echo "test"
}

function __cmd__cluster-manager__trace-debug()
{
	echo "test"
}


function __cmd__cluster-manager()
{
    local cur=${COMP_WORDS[COMP_CWORD]}
    COMPREPLY=( $(compgen -W "add delete list start stop restart trace-debug" -- $cur) )
	case $cur in
	add)
        __cmd__cluster-manager__add
		;;
	esac
}

complete -F __cmd__cluster-manager cluster-manager
