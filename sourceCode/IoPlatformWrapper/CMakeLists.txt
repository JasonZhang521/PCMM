aux_source_directory(. ioplatformwrapper_SRCS)

include_directories ("${PROJECT_SOURCE_DIR}/TraceLog"
"${PROJECT_SOURCE_DIR}/Common"
"${PROJECT_SOURCE_DIR}/Configure"
)

add_library(ioplatformwrapper  ${ioplatformwrapper_SRCS})

target_link_libraries(ioplatformwrapper
	                  configure
		              common
		             )

