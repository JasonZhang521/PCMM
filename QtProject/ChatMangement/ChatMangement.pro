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
    ../../sourceCode/Common/RemoveCharacter.cpp \
    ../../sourceCode/Network/NetworkEnv.cpp \
    ../../sourceCode/PlatformWrapper/SystemErrorInfo.cpp \
    ../../sourceCode/Common/Lock.cpp \
    ../../sourceCode/PlatformWrapper/NetworkHost.cpp \
    ../../sourceCode/Configure/SystemEnvironmentConfigure.cpp \
    ../../sourceCode/PlatformWrapper/SystemApi.cpp \
    ../../sourceCode/Common/CoredumpConfig.cpp \
    ../../sourceCode/Io/IoControlEventsHandlerEpoll.cpp \
    ../../sourceCode/ChatSessionManagement/ChatMgtConnectionAcceptor.cpp \
    ../../sourceCode/Ipc/IIpcConnectionClientStrategy.cpp \
    ../../sourceCode/Ipc/IpcClient.cpp \
    ../../sourceCode/IpcMessage/IpcMessageIdGenerator.cpp \
    ../../sourceCode/IpcMessage/IIpcMessage.cpp \
    ../../sourceCode/Common/FilePathHandler.cpp \
    ../../sourceCode/Common/LocalTime.cpp \
    ../../sourceCode/Common/Random.cpp \
    ../../sourceCode/Common/replace_character.cpp \
    ../../sourceCode/Common/SystemTime.cpp \
    ../../sourceCode/Common/TimeStat.cpp \
    ../../sourceCode/Serialize/ISerializable.cpp \
    ../../sourceCode/Serialize/ReadBuffer.cpp \
    ../../sourceCode/Serialize/WriteBuffer.cpp \
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
    ../../sourceCode/Configure/Configure.cpp \
    ../../sourceCode/Configure/ExceptionConfigure.cpp \
    ../../sourceCode/Configure/TraceLogConfigure.cpp \
    ../../sourceCode/ChatSessionManagement/IChatMgtControl.cpp \
    ../../sourceCode/ChatSessionManagement/ChatMgtControl.cpp \
    ../../sourceCode/ChatSessionManagement/ChatMgtConnectionReceiver.cpp \
    ../../sourceCode/ChatSessionManagement/ChatManagementProcess.cpp \
    ../../sourceCode/ConfigureManagement/NetworkConfig.cpp \
    ../../sourceCode/ChatSessionManagement/ChatManagementMain.cpp \
    ../../sourceCode/ChatSessionMessage/IChatMessage.cpp \
    ../../sourceCode/Common/MessageBuffer.cpp \
    ../../sourceCode/ChatSessionMessage/ChatTextMessage.cpp \
    ../../sourceCode/ChatSessionMessage/ChatFileMessage.cpp \
    ../../sourceCode/ChatSessionMessage/ChatAuthorizationRequest.cpp \
    ../../sourceCode/ChatSessionMessage/ChatAuthorizationResponse.cpp \
    ../../sourceCode/ChatSessionMessage/ChatLoginRequest.cpp \
    ../../sourceCode/ChatSessionMessage/ChatLoginResponse.cpp \
    ../../sourceCode/Common/Encryption.cpp \
    ../../sourceCode/ChatSessionMessage/ChatFileFragmentRequest.cpp \
    ../../sourceCode/ChatSessionMessage/ChatFileRequest.cpp \
    ../../sourceCode/ChatSessionMessage/ChatSessionMessageFactory.cpp

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
               ../../sourceCode/PlatformWrapper \
               ../../sourceCode/IpcMessage \
               ../../sourceCode/Serialize \
               ../../sourceCode/ConfigureManagement \
               ../../sourceCode/ChatSessionMessage \
               ../../sourceCode/ChatSessionManagement
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    ../../sourceCode/Ipc/Component.h \
    ../../sourceCode/Ipc/IIpcConnectionClientStrategy.h \
    ../../sourceCode/Ipc/IpcClient.h \
    ../../sourceCode/IpcMessage/IpcMessageIdGenerator.h \
    ../../sourceCode/IpcMessage/IIpcMessage.h \
    ../../sourceCode/IpcMessage/IpcMessageType.h \
    ../../sourceCode/Common/App.h \
    ../../sourceCode/Common/AppConst.h \
    ../../sourceCode/Common/FilePathHandler.h \
    ../../sourceCode/Common/LocalTime.h \
    ../../sourceCode/Common/Macro.h \
    ../../sourceCode/Common/operator.h \
    ../../sourceCode/Common/Random.h \
    ../../sourceCode/Common/replace_character.h \
    ../../sourceCode/Common/SystemTime.h \
    ../../sourceCode/Common/TimeStat.h \
    ../../sourceCode/Serialize/BufferToData.h \
    ../../sourceCode/Serialize/DataToBuffer.h \
    ../../sourceCode/Serialize/ISerializable.h \
    ../../sourceCode/Serialize/ReadBuffer.h \
    ../../sourceCode/Serialize/WriteBuffer.h \
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
    ../../sourceCode/Common/RemoveCharacter.h \
    ../../sourceCode/Network/NetworkEnv.h \
    ../../sourceCode/PlatformWrapper/SystemErrorInfo.h \
    ../../sourceCode/Common/Lock.h \
    ../../sourceCode/Common/Generic.h \
    ../../sourceCode/PlatformWrapper/NetworkHost.h \
    ../../sourceCode/Configure/SystemEnvironmentConfigure.h \
    ../../sourceCode/PlatformWrapper/SystemApi.h \
    ../../sourceCode/Common/CoredumpConfig.h \
    ../../sourceCode/Io/IoControlEventsHandlerEpoll.h \
    ../../sourceCode/ChatSessionManagement/ChatMgtConnectionAcceptor.h \
    ../../sourceCode/ChatSessionManagement/IChatMgtControl.h \
    ../../sourceCode/ChatSessionManagement/ChatMgtControl.h \
    ../../sourceCode/ChatSessionManagement/Component.h \
    ../../sourceCode/ChatSessionManagement/ChatMgtConnectionReceiver.h \
    ../../sourceCode/ChatSessionManagement/ChatManagementProcess.h \
    ../../sourceCode/ConfigureManagement/Component.h \
    ../../sourceCode/ConfigureManagement/NetworkConfig.h \
    ../../sourceCode/ChatSessionMessage/IChatMessage.h \
    ../../sourceCode/Common/MessageBuffer.h \
    ../../sourceCode/ChatSessionMessage/ChatTextMessage.h \
    ../../sourceCode/ChatSessionMessage/ChatFileMessage.h \
    ../../sourceCode/ChatSessionMessage/ChatAuthorizationRequest.h \
    ../../sourceCode/ChatSessionMessage/ChatAuthorizationResponse.h \
    ../../sourceCode/ChatSessionMessage/ChatLoginRequest.h \
    ../../sourceCode/ChatSessionMessage/ChatLoginResponse.h \
    ../../sourceCode/Common/Encryption.h \
    ../../sourceCode/ChatSessionMessage/ChatFileFragmentRequest.h \
    ../../sourceCode/ChatSessionMessage/ChatFileRequest.h \
    ../../sourceCode/ChatSessionMessage/ChatSessionMessageFactory.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../sourceCode/static_lib/ -lssh.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../sourceCode/static_lib/ -lssh.dll

LIBS += -lWs2_32
