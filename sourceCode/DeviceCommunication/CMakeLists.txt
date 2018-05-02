aux_source_directory(. DeviceCommunication_SRCS)
include_directories ("${PROJECT_SOURCE_DIR}/Environment"
                     "${PROJECT_SOURCE_DIR}/Common"
                     "${PROJECT_SOURCE_DIR}/Configure"
                     "${PROJECT_SOURCE_DIR}/Network"
                     "${PROJECT_SOURCE_DIR}/Io"
                     "${PROJECT_SOURCE_DIR}/PlatformWrapper"
                     "${PROJECT_SOURCE_DIR}/Core"
                     "${PROJECT_SOURCE_DIR}/DeviceCommunication"
                     "${PROJECT_SOURCE_DIR}/DeviceMessage"
                     "${PROJECT_SOURCE_DIR}/EventHandler"
                     "${PROJECT_SOURCE_DIR}/TimerHandler"
                     "${PROJECT_SOURCE_DIR}/TraceLog"
                     "${PROJECT_SOURCE_DIR}/Serialize"
                     "${PROJECT_SOURCE_DIR}/Network"
                     "${PROJECT_SOURCE_DIR}/ConfigureManagement"
)

add_library(devicecommunication  ${DeviceCommunication_SRCS})

target_link_libraries (devicecommunication
		               configure
					   common
					   environment
                                           devicemessage
					   network
					   io
					   platformwrapper
					   core
					   eventhandler
					   timerhandler
					   serialize
					   configuremanagement
					   ${LIBs}
					  )

