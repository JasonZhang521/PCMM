QT += core
QT -= gui

CONFIG += c++11

TARGET = ClusterManagement
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11
TEMPLATE = app

SOURCES += \
    ../../sourceCode/Network/ITcpConnectionAcceptor.cpp \
    ../../sourceCode/Ipc/IIpcServer.cpp \
    ../../sourceCode/Ipc/IIpcConnectionServerStrategy.cpp \
    ../../sourceCode/Ipc/IpcServer.cpp \
    ../../sourceCode/Ipc/IpcConnectionTcpServerStrategy.cpp \
    ../../sourceCode/Ipc/IpcConnectionTcpClientStrategy.cpp \
    ../../sourceCode/Ipc/IIpcConnectionAcceptor.cpp \
    ../../sourceCode/ClusterManagement/ClusterMgtClientsManagement.cpp \
    ../../sourceCode/ClusterManagement/ClusterMgtConnectionAcceptor.cpp \
    ../../sourceCode/ClusterManagement/ClusterMgtConnectionReceiver.cpp \
    ../../sourceCode/ClusterManagement/IClusterMgtClientsManagement.cpp \
    ../../sourceCode/ClusterManagement/IClusterMgtController.cpp \
    ../../sourceCode/ClusterManagement/ClusterMgtController.cpp \
    ../../sourceCode/ClusterManagement/ClusterManagementProcess.cpp \
    ../../sourceCode/ClusterManagement/ClusterManagementMain.cpp \
    ../../sourceCode/Network/TcpState.cpp \
    ../../sourceCode/Ipc/IpcClientCreator.cpp \
    ../../sourceCode/Ipc/IpcConnectionTimer.cpp \
    ../../sourceCode/Ipc/IpcHeartbeatTimer.cpp \
    ../../sourceCode/IpcMessage/IpcLayerMessageFactory.cpp \
    ../../sourceCode/IpcMessage/IpcHeartbeatReport.cpp \
    ../../sourceCode/IpcMessage/IpcMessageType.cpp \
    ../../sourceCode/IpcMessage/IIpcComunicationMessage.cpp \
    ../../sourceCode/IpcMessage/IpcAuthorizationRequest.cpp \
    ../../sourceCode/IpcMessage/IpcAuthorizationResponse.cpp \
    ../../sourceCode/Ipc/IpcServerCreator.cpp \
    ../../sourceCode/Environment/CpuInfo.cpp \
    ../../sourceCode/Environment/NetworkInfo.cpp \
    ../../sourceCode/Environment/DiskUsageInfo.cpp \
    ../../sourceCode/Environment/MomeryUsageInfo.cpp \
    ../../sourceCode/Environment/MiscInfo.cpp \
    ../../sourceCode/Environment/ComputerNodeInfo.cpp \
    ../../sourceCode/Environment/CpuInfoDataType.cpp \
    ../../sourceCode/Common/RemoveCharacter.cpp \
    ../../sourceCode/ClusterMgtMessage/IClusterMgtMessage.cpp \
    ../../sourceCode/ClusterMgtMessage/ClusterMgtBrieflyRequest.cpp \
    ../../sourceCode/ClusterMgtMessage/ClusterMgtBrieflyResponse.cpp \
    ../../sourceCode/Environment/CpuInfoBriefly.cpp \
    ../../sourceCode/Environment/EnvironmentSystemInfomation.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


INCLUDEPATH += ../../sourceCode/Serialize \
               ../../sourceCode/Common \
               ../../sourceCode/TraceLog \
               ../../sourceCode/Configure \
               ../../sourceCode/EventHandler \
               ../../sourceCode/TimerHandler \
               ../../sourceCode/Network \
               ../../sourceCode/Ipc \
               ../../sourceCode/Io \
               ../../sourceCode/Core \
               ../../sourceCode/Connection \
               ../../sourceCode/IoPlatformWrapper \
               ../../sourceCode/Environment \
               ../../sourceCode/IpcMessage \
               ../../sourceCode/SystemMonitorMessage
               ../../sourceCode/Serialize
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=../../sourceCode/Ipc/IIpcConnectionClientStrategy.cpp \
    ../../sourceCode/Ipc/IpcClient.cpp \
    ../../sourceCode/IpcMessage/IpcMessageIdGenerator.cpp \
    ../../sourceCode/IpcMessage/IIpcMessage.cpp \
    ../../sourceCode/Common/FilePathHandler.cpp \
    ../../sourceCode/Common/LocalTime.cpp \
    ../../sourceCode/Common/Random.cpp \
    ../../sourceCode/Common/replace_character.cpp \
    ../../sourceCode/Common/SystemTime.cpp \
    ../../sourceCode/Common/TimeStat.cpp \
    ../../sourceCode/SystemMonitorMessage/ISystemMonitorMessage.cpp \
    ../../sourceCode/SystemMonitorMessage/SystemInfoMessage.cpp \
    ../../sourceCode/Serialize/ISerializable.cpp \
    ../../sourceCode/Serialize/ReadBuffer.cpp \
    ../../sourceCode/Serialize/WriteBuffer.cpp \
    ../../sourceCode/Environment/CpuUsage.cpp \
    ../../sourceCode/Environment/CpuUsageCalculator.cpp \
    ../../sourceCode/Environment/CpuUsageInfo.cpp \
    ../../sourceCode/Network/IpAddress.cpp \
    ../../sourceCode/Network/IpPort.cpp \
    ../../sourceCode/Network/IpSocketEndpoint.cpp \
    ../../sourceCode/Network/ITcpClient.cpp \
    ../../sourceCode/Network/ITcpServer.cpp \
    ../../sourceCode/Network/SocketImp.cpp \
    ../../sourceCode/Network/TcpClient.cpp \
    ../../sourceCode/Network/TcpServer.cpp \
    ../../sourceCode/Network/TcpSocket.cpp \
    ../../sourceCode/IoPlatformWrapper/SocketWrapper.cpp \
    ../../sourceCode/SystemMonitorMessage/SystemInfoRequest.cpp \
    ../../sourceCode/EventHandler/EventIdGenerator.cpp \
    ../../sourceCode/EventHandler/IEvent.cpp \
    ../../sourceCode/EventHandler/IEventQueue.cpp \
    ../../sourceCode/EventHandler/ListEventQueue.cpp \
    ../../sourceCode/TimerHandler/EventTimer.cpp \
    ../../sourceCode/TimerHandler/ITimer.cpp \
    ../../sourceCode/TimerHandler/ITimerQueue.cpp \
    ../../sourceCode/TimerHandler/ListTimerQueue.cpp \
    ../../sourceCode/TimerHandler/TimerIdGenerator.cpp \
    ../../sourceCode/Core/EventLoop.cpp \
    ../../sourceCode/Core/LoopMain.cpp \
    ../../sourceCode/Io/IIoControl.cpp \
    ../../sourceCode/Io/IoControlEventsHandler.cpp \
    ../../sourceCode/Core/IoLoop.cpp \
    ../../sourceCode/Core/TimerLoop.cpp \
    ../../sourceCode/Io/IIoEvent.cpp \
    ../../sourceCode/Ipc/IIpcClient.cpp \
    ../../sourceCode/Network/ITcpConnectionReceiver.cpp \
    ../../sourceCode/Ipc/IIpcConnectionReceiver.cpp \
    ../../sourceCode/IpcMessage/IIpcMessageFactory.cpp \
    ../../sourceCode/SystemMonitorMessage/SystemMonitorMessageFactory.cpp \
    ../../sourceCode/Configure/Configure.cpp \
    ../../sourceCode/Configure/ExceptionConfigure.cpp \
    ../../sourceCode/Configure/TraceLogConfigure.cpp \
    ../../sourceCode/Environment/CpuUsageDataType.cpp

HEADERS += \
    ../../sourceCode/SystemMonitor/SystemMonitorProcess.h \
    ../../sourceCode/Ipc/Component.h \
    ../../sourceCode/Ipc/IIpcConnectionClientStrategy.h \
    ../../sourceCode/Ipc/IpcClient.h \
    ../../sourceCode/IpcMessage/IpcMessageIdGenerator.h \
    ../../sourceCode/IpcMessage/IIpcMessage.h \
    ../../sourceCode/IpcMessage/IpcMessageType.h \
    ../../sourceCode/Common/App.h \
    ../../sourceCode/Common/AppConst.h \
    ../../sourceCode/Common/FilePathHandler.h \
    ../../sourceCode/Common/generic.h \
    ../../sourceCode/Common/LocalTime.h \
    ../../sourceCode/Common/Macro.h \
    ../../sourceCode/Common/operator.h \
    ../../sourceCode/Common/Random.h \
    ../../sourceCode/Common/replace_character.h \
    ../../sourceCode/Common/SystemTime.h \
    ../../sourceCode/Common/TimeStat.h \
    ../../sourceCode/SystemMonitorMessage/ISystemMonitorMessage.h \
    ../../sourceCode/SystemMonitorMessage/SystemInfoMessage.h \
    ../../sourceCode/SystemMonitorMessage/Component.h \
    ../../sourceCode/Serialize/BufferToData.h \
    ../../sourceCode/Serialize/DataToBuffer.h \
    ../../sourceCode/Serialize/ISerializable.h \
    ../../sourceCode/Serialize/ReadBuffer.h \
    ../../sourceCode/Serialize/WriteBuffer.h \
    ../../sourceCode/Environment/Component.h \
    ../../sourceCode/Environment/CpuUsage.h \
    ../../sourceCode/Environment/CpuUsageCalculator.h \
    ../../sourceCode/Environment/CpuUsageDataType.h \
    ../../sourceCode/Environment/CpuUsageInfo.h \
    ../../sourceCode/Network/IpAddress.h \
    ../../sourceCode/Network/IpPort.h \
    ../../sourceCode/Network/IpSocketEndpoint.h \
    ../../sourceCode/Network/ITcpClient.h \
    ../../sourceCode/Network/ITcpServer.h \
    ../../sourceCode/Network/SocketImp.h \
    ../../sourceCode/Network/TcpClient.h \
    ../../sourceCode/Network/TcpServer.h \
    ../../sourceCode/Network/TcpSocket.h \
    ../../sourceCode/Network/TcpState.h \
    ../../sourceCode/Network/Component.h \
    ../../sourceCode/IoPlatformWrapper/SocketWrapper.h \
    ../../sourceCode/IoPlatformWrapper/SocketWrapperDef.h \
    ../../sourceCode/SystemMonitorMessage/SystemInfoRequest.h \
    ../../sourceCode/EventHandler/Component.h \
    ../../sourceCode/EventHandler/EventIdGenerator.h \
    ../../sourceCode/EventHandler/IEvent.h \
    ../../sourceCode/EventHandler/IEventQueue.h \
    ../../sourceCode/EventHandler/ListEventQueue.h \
    ../../sourceCode/TimerHandler/Component.h \
    ../../sourceCode/TimerHandler/EventTimer.h \
    ../../sourceCode/TimerHandler/ITimer.h \
    ../../sourceCode/TimerHandler/ITimerQueue.h \
    ../../sourceCode/TimerHandler/ListTimerQueue.h \
    ../../sourceCode/TimerHandler/TimerIdGenerator.h \
    ../../sourceCode/Core/EventLoop.h \
    ../../sourceCode/Core/LoopMain.h \
    ../../sourceCode/Io/Component.h \
    ../../sourceCode/Io/IIoControl.h \
    ../../sourceCode/Io/IoControlEventsHandler.h \
    ../../sourceCode/Core/IoLoop.h \
    ../../sourceCode/Core/TimerLoop.h \
    ../../sourceCode/Common/Singleton.h \
    ../../sourceCode/Serialize/Component.h \
    ../../sourceCode/Io/IIoEvent.h \
    ../../sourceCode/Ipc/IIpcClient.h \
    ../../sourceCode/Network/ITcpConnectionReceiver.h \
    ../../sourceCode/Ipc/IIpcConnectionReceiver.h \
    ../../sourceCode/IpcMessage/IIpcMessageFactory.h \
    ../../sourceCode/SystemMonitorMessage/SystemMonitorMessageFactory.h \
    ../../sourceCode/Configure/Configure.h \
    ../../sourceCode/Configure/Configure_Define.h \
    ../../sourceCode/Configure/ExceptionConfigure.h \
    ../../sourceCode/Configure/TraceLogConfigure.h \
    ../../sourceCode/Network/tcpResult.h \
    ../../sourceCode/Network/ITcpConnectionAcceptor.h \
    ../../sourceCode/Ipc/IIpcServer.h \
    ../../sourceCode/Ipc/IIpcConnectionServerStrategy.h \
    ../../sourceCode/Ipc/IpcServer.h \
    ../../sourceCode/Ipc/IpcConnectionTcpServerStrategy.h \
    ../../sourceCode/Ipc/IpcConnectionTcpClientStrategy.h \
    ../../sourceCode/Ipc/IIpcConnectionAcceptor.h \
    ../../sourceCode/ClusterManagement/IClusterMgtClientsManagement.h \
    ../../sourceCode/ClusterManagement/ClusterMgtConnectionReceiver.h \
    ../../sourceCode/ClusterManagement/ClusterMgtConnectionAcceptor.h \
    ../../sourceCode/ClusterManagement/ClusterMgtClientsManagement.h \
    ../../sourceCode/ClusterManagement/Component.h \
    ../../sourceCode/ClusterManagement/IClusterMgtController.h \
    ../../sourceCode/ClusterManagement/ClusterMgtController.h \
    ../../sourceCode/ClusterManagement/ClusterMgtClientType.h \
    ../../sourceCode/ClusterManagement/ClusterManagementProcess.h \
    ../../sourceCode/Common/Sleep.h \
    ../../sourceCode/TraceLog/Trace.h \
    ../../sourceCode/TraceLog/TraceBuf.h \
    ../../sourceCode/TraceLog/TraceConsole.h \
    ../../sourceCode/TraceLog/TraceFile.h \
    ../../sourceCode/Ipc/IpcClientCreator.h \
    ../../sourceCode/Ipc/IpcConnectionTimer.h \
    ../../sourceCode/Ipc/IpcHeartbeatTimer.h \
    ../../sourceCode/IpcMessage/IpcHeartbeatReport.h \
    ../../sourceCode/IpcMessage/IpcLayerMessageFactory.h \
    ../../sourceCode/IpcMessage/IIpcComunicationMessage.h \
    ../../sourceCode/IpcMessage/IpcAuthorizationRequest.h \
    ../../sourceCode/IpcMessage/IpcAuthorizationResponse.h \
    ../../sourceCode/Ipc/IpcServerCreator.h \
    ../../sourceCode/Environment/CpuInfo.h \
    ../../sourceCode/Environment/NetworkInfo.h \
    ../../sourceCode/Environment/DiskUsageInfo.h \
    ../../sourceCode/Environment/MomeryUsageInfo.h \
    ../../sourceCode/Environment/MiscInfo.h \
    ../../sourceCode/Environment/ComputerNodeInfo.h \
    ../../sourceCode/Environment/CpuInfoDataType.h \
    ../../sourceCode/Common/RemoveCharacter.h \
    ../../sourceCode/ClusterMgtMessage/IClusterMgtMessage.h \
    ../../sourceCode/ClusterMgtMessage/ClusterMgtBrieflyRequest.h \
    ../../sourceCode/ClusterMgtMessage/ClusterMgtBrieflyResponse.h \
    ../../sourceCode/Environment/CpuInfoBriefly.h \
    ../../sourceCode/Environment/EnvironmentSystemInfomation.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../sourceCode/static_lib/ -lssh.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../sourceCode/static_lib/ -lssh.dll

LIBS += -lWs2_32
