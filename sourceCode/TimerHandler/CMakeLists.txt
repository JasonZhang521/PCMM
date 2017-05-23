aux_source_directory(. timehandler_SRCS)

include_directories ("${PROJECT_SOURCE_DIR}/TraceLog"
"${PROJECT_SOURCE_DIR}/Common"
"${PROJECT_SOURCE_DIR}/Configure"
"${PROJECT_SOURCE_DIR}/EventHandler"
)

add_library(timehandler  ${timehandler_SRCS})

target_link_libraries(timehandler ${SSH_LIBs}
	                  configure
		              common
		             )

