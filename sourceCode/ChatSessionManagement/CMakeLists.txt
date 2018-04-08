aux_source_directory(. ChatSessionManagement_SRCS)
include_directories ("${PROJECT_SOURCE_DIR}/Environment"
                     "${PROJECT_SOURCE_DIR}/Common"
                     "${PROJECT_SOURCE_DIR}/Configure"
                     "${PROJECT_SOURCE_DIR}/Ipc"
                     "${PROJECT_SOURCE_DIR}/IpcMessage"
                     "${PROJECT_SOURCE_DIR}/Network"
                     "${PROJECT_SOURCE_DIR}/Io"
	             "${PROJECT_SOURCE_DIR}/PlatformWrapper"
                     "${PROJECT_SOURCE_DIR}/Core"
                     "${PROJECT_SOURCE_DIR}/ChatSessionMessage"
                     "${PROJECT_SOURCE_DIR}/EventHandler"
                     "${PROJECT_SOURCE_DIR}/TimerHandler"
                     "${PROJECT_SOURCE_DIR}/TraceLog"
                     "${PROJECT_SOURCE_DIR}/Serialize"
                     "${PROJECT_SOURCE_DIR}/ConfigureManagement"
                     "${PROJECT_SOURCE_DIR}/ChatSessionManagement"
																										 
)
add_executable(ChatSessionManager.elf ${ChatSessionManagement_SRCS})
target_link_libraries (ChatSessionManager.elf
		               configure
					   common
					   ipc
					   ipcmessage
					   network
					   io
					   platformwrapper
					   core
					   chatsessionmessage
					   eventhandler
					   timerhandler
					   serialize
					   configuremanagement
					   ${LIBs}
					  )
