set(SshOneTimeShellCmdMainTest_SRCS
    SshOneTimeShellCmdMainTest.cpp
)
include_directories ("${PROJECT_SOURCE_DIR}/TraceLog"
"${PROJECT_SOURCE_DIR}/Common"
"${PROJECT_SOURCE_DIR}/Configure"
"${PROJECT_SOURCE_DIR}/SshWrapper"
)
add_executable(SshOneTimeShellCmdMainTest.elf ${SshOneTimeShellCmdMainTest_SRCS})
target_link_libraries (SshOneTimeShellCmdMainTest.elf ${SSH_LIBs}
		configure
		common
		sshwrapper
		)
