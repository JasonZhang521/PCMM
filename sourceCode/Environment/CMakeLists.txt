aux_source_directory(. environment_SRCS)

include_directories ("${PROJECT_SOURCE_DIR}/TraceLog"
"${PROJECT_SOURCE_DIR}/Common"
"${PROJECT_SOURCE_DIR}/Configure"
)

add_library(environment  ${environment_SRCS})

target_link_libraries(environment
	                  configure
		              common
		             )

