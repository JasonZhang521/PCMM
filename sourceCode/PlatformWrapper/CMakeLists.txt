aux_source_directory(. platformwrapper_SRCS)

include_directories ("${PROJECT_SOURCE_DIR}/TraceLog"
"${PROJECT_SOURCE_DIR}/Common"
"${PROJECT_SOURCE_DIR}/Configure"
)

add_library(platformwrapper  ${platformwrapper_SRCS})

target_link_libraries(platformwrapper
	                  configure
		              common
		             )

