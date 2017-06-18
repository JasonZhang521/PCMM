#-------------------------------------------------
#
# Project created by QtCreator 2017-06-09T20:39:28
#
#-------------------------------------------------

QT       -= core gui

TARGET = SystemMonitor
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
               ../../sourceCode/IoPlatformWrapper \
               ../../sourceCode/Environment \
               ../../sourceCode/IpcMessage \
               ../../sourceCode/SystemMonitorMessage
               ../../sourceCode/Serialize
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=../../sourceCode/SystemMonitor/SystemMonitorProcess.cpp \
    ../../sourceCode/Ipc/IIpcConnectionClientStrategy.cpp \
    ../../sourceCode/Ipc/IpcClient.cpp \
    ../../sourceCode/Ipc/IpcConnectionTcpStrategy.cpp \
    ../../sourceCode/IpcMessage/IpcMessageIdGenerator.cpp \
    ../../sourceCode/IpcMessage/IIpcMessage.cpp \
    ../../sourceCode/Common/FilePathHandler.cpp \
    ../../sourceCode/Common/LocalTime.cpp \
    ../../sourceCode/Common/Random.cpp \
    ../../sourceCode/Common/remove_character.cpp \
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
    ../../sourceCode/SystemMonitor/SystemMonitorHandler.cpp \
    ../../sourceCode/SystemMonitor/SystemInfoCollector.cpp \
    ../../sourceCode/SystemMonitor/ISystemMonitorHandler.cpp \
    ../../sourceCode/Io/IIoEvent.cpp \
    ../../sourceCode/Ipc/IIpcClient.cpp \
    ../../sourceCode/Network/ITcpConnectionReceiver.cpp \
    ../../sourceCode/Ipc/IIpcConnectionReceiver.cpp \
    ../../sourceCode/IpcMessage/IIpcMessageFactory.cpp \
    ../../sourceCode/SystemMonitorMessage/SystemMonitorMessageFactory.cpp \
    ../../sourceCode/SystemMonitor/SystemMonitorConnectionReceiver.cpp \
    ../../sourceCode/SystemMonitor/SystemmMonitorMain.cpp \
    ../../sourceCode/Configure/Configure.cpp \
    ../../sourceCode/Configure/ExceptionConfigure.cpp \
    ../../sourceCode/Configure/TraceLogConfigure.cpp \
    ../../sourceCode/Environment/CpuUsageDataType.cpp

HEADERS += \
    ../../sourceCode/SystemMonitor/SystemMonitorProcess.h \
    ../../sourceCode/Ipc/Component.h \
    ../../sourceCode/Ipc/IIpcConnectionClientStrategy.h \
    ../../sourceCode/Ipc/IpcClient.h \
    ../../sourceCode/Ipc/IpcConnectionTcpStrategy.h \
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
    ../../sourceCode/Common/remove_character.h \
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
    ../../sourceCode/Network/tcpresult.h \
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
    ../../sourceCode/SystemMonitor/SystemInfoCollector.h \
    ../../sourceCode/SystemMonitor/Component.h \
    ../../sourceCode/SystemMonitor/ISystemMonitorHandler.h \
    ../../sourceCode/SystemMonitor/SystemMonitorHandler.h \
    ../../sourceCode/Serialize/Component.h \
    ../../sourceCode/Io/IIoEvent.h \
    ../../sourceCode/Ipc/IIpcClient.h \
    ../../sourceCode/Network/ITcpConnectionReceiver.h \
    ../../sourceCode/Ipc/IIpcConnectionReceiver.h \
    ../../sourceCode/IpcMessage/IIpcMessageFactory.h \
    ../../sourceCode/SystemMonitorMessage/SystemMonitorMessageFactory.h \
    ../../sourceCode/SystemMonitor/SystemMonitorConnectionReceiver.h \
    ../../sourceCode/Configure/Configure.h \
    ../../sourceCode/Configure/Configure_Define.h \
    ../../sourceCode/Configure/ExceptionConfigure.h \
    ../../sourceCode/Configure/TraceLogConfigure.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../sourceCode/static_lib/ -lssh.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../sourceCode/static_lib/ -lssh.dll

LIBS += -lWs2_32
