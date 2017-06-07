aux_source_directory(. Environment_Unittest_SRCS)
include_directories ("${PROJECT_SOURCE_DIR}/Environment"
"${PROJECT_SOURCE_DIR}/Common"
"${PROJECT_SOURCE_DIR}/Configure"
)
add_executable(Environment_unittest.elf ${Environment_Unittest_SRCS})
target_link_libraries (Environment_unittest.elf configure common environment ${TEST_LIBs})
