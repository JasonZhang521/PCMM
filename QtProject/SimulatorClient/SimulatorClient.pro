QT += core
QT -= gui

TARGET = SimulatorClient

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
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
               ../../sourceCode/PlatformWrapper \
               ../../sourceCode/Environment \
               ../../sourceCode/IpcMessage \
               ../../sourceCode/SystemMonitorMessage \
               ../../sourceCode/Serialize \
               ../../sourceCode/DeviceCommunication \
               ../../sourceCode/DeviceMessage
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=../../sourceCode/Ipc/IIpcConnectionClientStrategy.cpp \
    ../../sourceCode/Ipc/IpcClient.cpp \
    ../../sourceCode/Ipc/IpcConnectionTcpClientStrategy.cpp \
    ../../sourceCode/IpcMessage/IpcMessageIdGenerator.cpp \
    ../../sourceCode/IpcMessage/IIpcMessage.cpp \
    ../../sourceCode/Common/FilePathHandler.cpp \
    ../../sourceCode/Common/LocalTime.cpp \
    ../../sourceCode/Common/Random.cpp \
    ../../sourceCode/Common/RemoveCharacter.cpp \
    ../../sourceCode/Common/replace_character.cpp \
    ../../sourceCode/Common/SystemTime.cpp \
    ../../sourceCode/Common/TimeStat.cpp \
    ../../sourceCode/SystemMonitorMessage/ISystemMonitorMessage.cpp \
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
    ../../sourceCode/PlatformWrapper/SocketWrapper.cpp \
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
    ../../sourceCode/Environment/CpuUsageDataType.cpp \
    ../../sourceCode/Network/TcpState.cpp \
    ../../sourceCode/Network/NetworkEnv.cpp \
    ../../sourceCode/Ipc/IpcClientCreator.cpp \
    ../../sourceCode/IpcMessage/IpcMessageType.cpp \
    ../../sourceCode/Ipc/IpcHeartbeatTimer.cpp \
    ../../sourceCode/IpcMessage/IpcLayerMessageFactory.cpp \
    ../../sourceCode/IpcMessage/IpcHeartbeatReport.cpp \
    ../../sourceCode/Ipc/IpcConnectionTimer.cpp \
    ../../sourceCode/IpcMessage/IIpcComunicationMessage.cpp \
    ../../sourceCode/IpcMessage/IpcAuthorizationRequest.cpp \
    ../../sourceCode/IpcMessage/IpcAuthorizationResponse.cpp \
    ../../sourceCode/SimulatorClient/UiIpcConnectionReceiver.cpp \
    ../../sourceCode/SimulatorClient/IUiClientHandler.cpp \
    ../../sourceCode/SimulatorClient/UiClientHandler.cpp \
    ../../sourceCode/SimulatorClient/UiClientProcess.cpp \
    ../../sourceCode/SimulatorClient/UiClientMain.cpp \
    ../../sourceCode/IpcMessage/IIpcMessageQueue.cpp \
    ../../sourceCode/Common/Lock.cpp \
    ../../sourceCode/IpcMessage/IpcThreadSafeMessageQueue.cpp \
    ../../sourceCode/SimulatorClient/UiClientMessageSendTimer.cpp \
    ../../sourceCode/Environment/ComputerNodeInfo.cpp \
    ../../sourceCode/Environment/CpuInfo.cpp \
    ../../sourceCode/Environment/CpuInfoBriefly.cpp \
    ../../sourceCode/Environment/DiskUsageInfo.cpp \
    ../../sourceCode/Environment/EnvironmentSystemInfomation.cpp \
    ../../sourceCode/Environment/MemoryInfo.cpp \
    ../../sourceCode/Environment/MemoryInfoBriefly.cpp \
    ../../sourceCode/Environment/MemoryUsageInfo.cpp \
    ../../sourceCode/Environment/MemoryUsageInfoDataType.cpp \
    ../../sourceCode/Environment/MiscInfo.cpp \
    ../../sourceCode/Environment/NetworkInfo.cpp \
    ../../sourceCode/Environment/SystemInfoBriefly.cpp \
    ../../sourceCode/PlatformWrapper/SystemErrorInfo.cpp \
    ../../sourceCode/Environment/CpuInfoDataType.cpp \
    ../../sourceCode/Environment/ShellCommandDataType.cpp \
    ../../sourceCode/Environment/ShellCommandDfOutput.cpp \
    ../../sourceCode/Environment/ShellCommandOutputParse.cpp \
    ../../sourceCode/Environment/ShellCommandProcess.cpp \
    ../../sourceCode/Environment/ShellCommandThread.cpp \
    ../../sourceCode/Environment/Environment.cpp \
    ../../sourceCode/Environment/IShellCommand.cpp \
    ../../sourceCode/SystemMonitorMessage/ComputerNodeInfoReport.cpp \
    ../../sourceCode/SystemMonitorMessage/ComputerNodeInfoRequest.cpp \
    ../../sourceCode/SystemMonitorMessage/ControlNodeBrieflyInfoRequest.cpp \
    ../../sourceCode/SystemMonitorMessage/ControlNodeBrieflyInfoResponse.cpp \
    ../../sourceCode/PlatformWrapper/NetworkHost.cpp \
    ../../sourceCode/Environment/ShellCommandPsTopnCpuUsageOutput.cpp \
    ../../sourceCode/Environment/ShellCommandPsTopnMemoryUsageOutput.cpp \
    ../../sourceCode/ShellCommandMessage/IShellCommandMessage.cpp \
    ../../sourceCode/ShellCommandMessage/ShellCommandMessageFactory.cpp \
    ../../sourceCode/ShellCommandMessage/ShellCommandRequest.cpp \
    ../../sourceCode/ShellCommandMessage/ShellCommandResponse.cpp \
    ../../sourceCode/Environment/ShellCommandGenericOutput.cpp \
    ../../sourceCode/Configure/SystemEnvironmentConfigure.cpp \
    ../../sourceCode/PlatformWrapper/SystemApi.cpp \
    ../../sourceCode/DeviceMessage/DeviceMessageType.cpp \
    ../../sourceCode/DeviceMessage/IDeviceMessage.cpp \
    ../../sourceCode/DeviceMessage/IoeZpMessage.cpp \
    ../../sourceCode/DeviceMessage/IoeZpResource.cpp \
    ../../sourceCode/DeviceCommunication/DeviceClient.cpp \
    ../../sourceCode/DeviceCommunication/DeviceClientManager.cpp \
    ../../sourceCode/DeviceCommunication/DeviceConnectionAcceptor.cpp \
    ../../sourceCode/DeviceCommunication/DeviceConnectionReceiverCreator.cpp \
    ../../sourceCode/DeviceCommunication/DeviceServer.cpp \
    ../../sourceCode/DeviceCommunication/DeviceServerCreator.cpp \
    ../../sourceCode/DeviceCommunication/IDeviceClient.cpp \
    ../../sourceCode/DeviceCommunication/IDeviceClientManager.cpp \
    ../../sourceCode/DeviceCommunication/IDeviceMessageHandler.cpp \
    ../../sourceCode/DeviceCommunication/IDeviceServer.cpp \
    ../../sourceCode/DeviceCommunication/IoeZpConnectionReceiver.cpp \
    ../../sourceCode/DeviceCommunication/IoeZpMessageHandler.cpp \
    ../../sourceCode/Environment/IoeZpDeviceInfo.cpp \
    ../../sourceCode/Common/Number.cpp \
    ../../sourceCode/Environment/DeviceInfo.cpp \
    ../../sourceCode/Network/ITcpConnectionAcceptor.cpp \
    ../../sourceCode/SimulatorClient/DeviceClientHandler.cpp \
    ../../sourceCode/SimulatorClient/IDeviceClientHandler.cpp

HEADERS += \
    ../../sourceCode/Ipc/Component.h \
    ../../sourceCode/Ipc/IIpcConnectionClientStrategy.h \
    ../../sourceCode/Ipc/IpcClient.h \
    ../../sourceCode/Ipc/IpcConnectionTcpClientStrategy.h \
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
    ../../sourceCode/Common/RemoveCharacter.h \
    ../../sourceCode/Common/replace_character.h \
    ../../sourceCode/Common/SystemTime.h \
    ../../sourceCode/Common/TimeStat.h \
    ../../sourceCode/SystemMonitorMessage/ISystemMonitorMessage.h \
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
    ../../sourceCode/Network/tcpresult.h \
    ../../sourceCode/Network/TcpServer.h \
    ../../sourceCode/Network/TcpSocket.h \
    ../../sourceCode/Network/TcpState.h \
    ../../sourceCode/Network/Component.h \
    ../../sourceCode/PlatformWrapper/SocketWrapper.h \
    ../../sourceCode/PlatformWrapper/SocketWrapperDef.h \
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
    ../../sourceCode/Network/NetworkEnv.h \
    ../../sourceCode/Ipc/IpcClientCreator.h \
    ../../sourceCode/Ipc/IpcHeartbeatTimer.h \
    ../../sourceCode/IpcMessage/IpcLayerMessageFactory.h \
    ../../sourceCode/IpcMessage/IpcHeartbeatReport.h \
    ../../sourceCode/Ipc/IpcConnectionTimer.h \
    ../../sourceCode/IpcMessage/IIpcComunicationMessage.h \
    ../../sourceCode/IpcMessage/IpcAuthorizationRequest.h \
    ../../sourceCode/IpcMessage/IpcAuthorizationResponse.h \
    ../../sourceCode/SimulatorClient/UiIpcConnectionReceiver.h \
    ../../sourceCode/SimulatorClient/IUiClientHandler.h \
    ../../sourceCode/SimulatorClient/UiClientHandler.h \
    ../../sourceCode/SimulatorClient/UiClientProcess.h \
    ../../sourceCode/SimulatorClient/Component.h \
    ../../sourceCode/IpcMessage/IIpcMessageQueue.h \
    ../../sourceCode/Common/Lock.h \
    ../../sourceCode/IpcMessage/IpcThreadSafeMessageQueue.h \
    ../../sourceCode/SimulatorClient/UiClientMessageSendTimer.h \
    ../../sourceCode/Environment/ComputerNodeInfo.h \
    ../../sourceCode/Environment/CpuInfo.h \
    ../../sourceCode/Environment/CpuInfoBriefly.h \
    ../../sourceCode/Environment/cpuinfodatatype.h \
    ../../sourceCode/Environment/DiskUsageInfo.h \
    ../../sourceCode/Environment/EnvironmentSystemInfomation.h \
    ../../sourceCode/Environment/MemoryInfo.h \
    ../../sourceCode/Environment/MemoryInfoBriefly.h \
    ../../sourceCode/Environment/MemoryUsageInfo.h \
    ../../sourceCode/Environment/MemoryUsageInfoDataType.h \
    ../../sourceCode/Environment/MiscInfo.h \
    ../../sourceCode/Environment/NetworkInfo.h \
    ../../sourceCode/Environment/SystemInfoBriefly.h \
    ../../sourceCode/PlatformWrapper/SystemErrorInfo.h \
    ../../sourceCode/Environment/ShellCommandDataType.h \
    ../../sourceCode/Environment/ShellCommandDfOutput.h \
    ../../sourceCode/Environment/ShellCommandOutputParse.h \
    ../../sourceCode/Environment/ShellCommandProcess.h \
    ../../sourceCode/Environment/ShellCommandThread.h \
    ../../sourceCode/Environment/Environment.h \
    ../../sourceCode/Environment/IShellCommand.h \
    ../../sourceCode/SystemMonitorMessage/ComputerNodeInfoReport.h \
    ../../sourceCode/SystemMonitorMessage/ComputerNodeInfoRequest.h \
    ../../sourceCode/SystemMonitorMessage/ControlNodeBrieflyInfoRequest.h \
    ../../sourceCode/SystemMonitorMessage/ControlNodeBrieflyInfoResponse.h \
    ../../sourceCode/PlatformWrapper/NetworkHost.h \
    ../../sourceCode/Environment/ShellCommandPsTopnCpuUsageOutput.h \
    ../../sourceCode/Environment/ShellCommandPsTopnMemoryUsageOutput.h \
    ../../sourceCode/ShellCommandMessage/Component.h \
    ../../sourceCode/ShellCommandMessage/IShellCommandMessage.h \
    ../../sourceCode/ShellCommandMessage/ShellCommandMessageFactory.h \
    ../../sourceCode/ShellCommandMessage/ShellCommandRequest.h \
    ../../sourceCode/ShellCommandMessage/ShellCommandResponse.h \
    ../../sourceCode/Environment/ShellCommandGenericOutput.h \
    ../../sourceCode/Configure/SystemEnvironmentConfigure.h \
    ../../sourceCode/TraceLog/Trace.h \
    ../../sourceCode/TraceLog/TraceBuf.h \
    ../../sourceCode/TraceLog/TraceConsole.h \
    ../../sourceCode/TraceLog/TraceFile.h \
    ../../sourceCode/PlatformWrapper/SystemApi.h \
    ../../sourceCode/DeviceMessage/Component.h \
    ../../sourceCode/DeviceMessage/DeviceMessageType.h \
    ../../sourceCode/DeviceMessage/IDeviceMessage.h \
    ../../sourceCode/DeviceMessage/IoeZpMessage.h \
    ../../sourceCode/DeviceMessage/IoeZpResource.h \
    ../../sourceCode/DeviceCommunication/Component.h \
    ../../sourceCode/DeviceCommunication/DeviceClient.h \
    ../../sourceCode/DeviceCommunication/DeviceConnectionAcceptor.h \
    ../../sourceCode/DeviceCommunication/DeviceConnectionReceiverCreator.h \
    ../../sourceCode/DeviceCommunication/DeviceServer.h \
    ../../sourceCode/DeviceCommunication/DeviceServerCreator.h \
    ../../sourceCode/DeviceCommunication/DeviceType.h \
    ../../sourceCode/DeviceCommunication/IDeviceClient.h \
    ../../sourceCode/DeviceCommunication/IDeviceClientManager.h \
    ../../sourceCode/DeviceCommunication/IDeviceMessageHandler.h \
    ../../sourceCode/DeviceCommunication/IDeviceServer.h \
    ../../sourceCode/DeviceCommunication/IoeZpConnectionReceiver.h \
    ../../sourceCode/DeviceCommunication/IoeZpMessageHandler.h \
    ../../sourceCode/Environment/IoeZpDeviceinfo.h \
    ../../sourceCode/Common/Number.h \
    ../../sourceCode/Environment/DeviceInfo.h \
    ../../sourceCode/Network/ITcpConnectionAcceptor.h \
    ../../sourceCode/SimulatorClient/DeviceClientHandler.h \
    ../../sourceCode/SimulatorClient/IDeviceClientHandler.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../sourceCode/static_lib/ -lssh.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../sourceCode/static_lib/ -lssh.dll

LIBS += -lWs2_32

