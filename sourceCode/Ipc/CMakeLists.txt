aux_source_directory(. ipc_SRCS)

include_directories ("${PROJECT_SOURCE_DIR}/TraceLog"
"${PROJECT_SOURCE_DIR}/Common"
"${PROJECT_SOURCE_DIR}/Configure"
)

add_library(ipc  ${ipc_SRCS})

target_link_libraries(ipc
	                  configure
		              common
		             )

