aux_source_directory(. timerhandler_SRCS)

include_directories ("${PROJECT_SOURCE_DIR}/TraceLog"
"${PROJECT_SOURCE_DIR}/Common"
"${PROJECT_SOURCE_DIR}/Configure"
"${PROJECT_SOURCE_DIR}/EventHandler"
)

add_library(timerhandler  ${timerhandler_SRCS})

target_link_libraries(timerhandler ${SSH_LIBs}
	                  configure
		              common
					  eventhandler
		             )

