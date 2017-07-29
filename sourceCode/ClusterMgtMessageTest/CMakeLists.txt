aux_source_directory(. ClusterMgtMessage_Unittest_SRCS)
include_directories ("${PROJECT_SOURCE_DIR}/ClusterMgtMessage"
"${PROJECT_SOURCE_DIR}/Common"
"${PROJECT_SOURCE_DIR}/Configure"
"${PROJECT_SOURCE_DIR}/ClusterMgtMessage"
"${PROJECT_SOURCE_DIR}/IpcMessage"
"${PROJECT_SOURCE_DIR}/Network"
"${PROJECT_SOURCE_DIR}/Serialize"
"${PROJECT_SOURCE_DIR}/IoPlatformWrapper"
"${PROJECT_SOURCE_DIR}/Environment"
)
add_executable(ClusterMgtMessage_unittest.elf ${ClusterMgtMessage_Unittest_SRCS})
target_link_libraries (ClusterMgtMessage_unittest.elf
		               configure
					   common
					   serialize
					   clustermgtmessage
					   ipcmessage
					   ${TEST_LIBs})
