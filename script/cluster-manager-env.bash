ScriptDir=/opt/HongClusterMgt/tools/
alias cluster-manager="$ScriptDir/cluster-manager.sh"

function __cmd__cluster_manager()
{
    local cur prev BASE_LEVEL
    COMPREPLY=()
    cur=${COMP_WORDS[COMP_CWORD]}
    prev=${COMP_WORDS[COMP_CWORD-1]}
    
    # Setup the base level
    if [ $COMP_CWORD -eq 1 ]; then
        COMPREPLY=( $(compgen -W "help add delete list start stop restart trace-debug" -- $cur) )
    # Setup the second level
    elif [ $COMP_CWORD -eq 2 ]; then
        case "$prev" in    
            "add"|"delete"|"list")
                COMPREPLY=( $(compgen -W "ui-server node-server" -- $cur) )
                ;;
            "start"|"stop"|"restart")
                COMPREPLY=( $(compgen -W "node-client server" -- $cur) )
                ;;
            "trace-debug")
                COMPREPLY=( $(compgen -W "level target" -- $cur) ) 
                ;;
            *)
                ;;
        esac
    elif [ $COMP_CWORD -eq 3 ]; then
        case "$prev" in
             "ui-server"|"node-server")
                  COMPREPLY=( $(compgen -W "ip:port" -- $cur) )
                  ;;
             "level")
                  COMPREPLY=( $(compgen -W "0 1 2 3 4" -- $cur) )
                  ;;
             "target")
                  COMPREPLY=( $(compgen -W "file console both" -- $cur) )
                  ;;
             *)
                  ;;
        esac
    fi
}

complete -F __cmd__cluster_manager cluster-manager
