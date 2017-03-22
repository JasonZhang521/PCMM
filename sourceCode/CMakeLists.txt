set(LIBs pthread)
set(TEST_LIBs ${LIBs} gtest gmock gtest_main gmock_main)
cmake_minimum_required (VERSION 2.6)

add_subdirectory(Configure)
add_subdirectory(Common)

#Unit test
add_subdirectory(ConfigureTest)
add_subdirectory(TraceLogTest)
