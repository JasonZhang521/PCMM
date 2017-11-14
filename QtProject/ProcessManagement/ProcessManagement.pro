QT += core
QT -= gui

CONFIG += c++11

TARGET = ProcessManagement
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    ../../sourceCode/Common/FilePathHandler.cpp \
    ../../sourceCode/Common/LocalTime.cpp \
    ../../sourceCode/Common/Lock.cpp \
    ../../sourceCode/Common/Random.cpp \
    ../../sourceCode/Common/RemoveCharacter.cpp \
    ../../sourceCode/Common/replace_character.cpp \
    ../../sourceCode/Common/SystemTime.cpp \
    ../../sourceCode/Common/TimeStat.cpp \
    ../../sourceCode/Configure/Configure.cpp \
    ../../sourceCode/Configure/ExceptionConfigure.cpp \
    ../../sourceCode/Configure/SystemEnvironmentConfigure.cpp \
    ../../sourceCode/Configure/TraceLogConfigure.cpp \
    ../../sourceCode/ProcessManagementSupport/IUnixProcess.cpp \
    ../../sourceCode/ProcessManagementSupport/UnixProcess.cpp \
    ../../sourceCode/ProcessManagement/ProcessHandler.cpp \
    ../../sourceCode/Core/EventLoop.cpp \
    ../../sourceCode/Core/IoLoop.cpp \
    ../../sourceCode/Core/LoopMain.cpp \
    ../../sourceCode/Core/TimerLoop.cpp \
    ../../sourceCode/TimerHandler/EventTimer.cpp \
    ../../sourceCode/TimerHandler/ITimer.cpp \
    ../../sourceCode/TimerHandler/ITimerQueue.cpp \
    ../../sourceCode/TimerHandler/ListTimerQueue.cpp \
    ../../sourceCode/TimerHandler/TimerIdGenerator.cpp \
    ../../sourceCode/Io/IIoControl.cpp \
    ../../sourceCode/Io/IIoEvent.cpp \
    ../../sourceCode/Io/IoControlEventsHandler.cpp \
    ../../sourceCode/EventHandler/EventIdGenerator.cpp \
    ../../sourceCode/EventHandler/IEvent.cpp \
    ../../sourceCode/EventHandler/IEventQueue.cpp \
    ../../sourceCode/EventHandler/ListEventQueue.cpp \
    ../../sourceCode/PlatformWrapper/NetworkHost.cpp \
    ../../sourceCode/PlatformWrapper/SocketWrapper.cpp \
    ../../sourceCode/PlatformWrapper/SystemApi.cpp \
    ../../sourceCode/PlatformWrapper/SystemErrorInfo.cpp \
    ../../sourceCode/ProcessManagement/processmanagementmain.cpp \
    ../../sourceCode/ProcessManagement/ProcessManagementProcess.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    ../../sourceCode/Common/App.h \
    ../../sourceCode/Common/AppConst.h \
    ../../sourceCode/Common/FilePathHandler.h \
    ../../sourceCode/Common/Generic.h \
    ../../sourceCode/Common/LocalTime.h \
    ../../sourceCode/Common/Lock.h \
    ../../sourceCode/Common/Macro.h \
    ../../sourceCode/Common/operator.h \
    ../../sourceCode/Common/Random.h \
    ../../sourceCode/Common/RemoveCharacter.h \
    ../../sourceCode/Common/replace_character.h \
    ../../sourceCode/Common/singleton.h \
    ../../sourceCode/Common/Sleep.h \
    ../../sourceCode/Common/SystemTime.h \
    ../../sourceCode/Common/TimeStat.h \
    ../../sourceCode/TraceLog/Trace.h \
    ../../sourceCode/TraceLog/TraceBuf.h \
    ../../sourceCode/TraceLog/TraceConsole.h \
    ../../sourceCode/TraceLog/TraceFile.h \
    ../../sourceCode/Configure/Configure.h \
    ../../sourceCode/Configure/Configure_Define.h \
    ../../sourceCode/Configure/ExceptionConfigure.h \
    ../../sourceCode/Configure/SystemEnvironmentConfigure.h \
    ../../sourceCode/Configure/TraceLogConfigure.h \
    ../../sourceCode/ProcessManagementSupport/Component.h \
    ../../sourceCode/ProcessManagementSupport/IUnixProcess.h \
    ../../sourceCode/ProcessManagementSupport/UnixProcess.h \
    ../../sourceCode/ProcessManagement/ProcessHandler.h \
    ../../sourceCode/ProcessManagement/Component.h \
    ../../sourceCode/Core/Component.h \
    ../../sourceCode/Core/EventLoop.h \
    ../../sourceCode/Core/IoLoop.h \
    ../../sourceCode/Core/LoopMain.h \
    ../../sourceCode/Core/TimerLoop.h \
    ../../sourceCode/TimerHandler/Component.h \
    ../../sourceCode/TimerHandler/EventTimer.h \
    ../../sourceCode/TimerHandler/ITimer.h \
    ../../sourceCode/TimerHandler/ITimerQueue.h \
    ../../sourceCode/TimerHandler/ListTimerQueue.h \
    ../../sourceCode/TimerHandler/TimerIdGenerator.h \
    ../../sourceCode/Io/Component.h \
    ../../sourceCode/Io/IIoControl.h \
    ../../sourceCode/Io/IIoEvent.h \
    ../../sourceCode/Io/IoControlEventsHandler.h \
    ../../sourceCode/EventHandler/Component.h \
    ../../sourceCode/EventHandler/EventIdGenerator.h \
    ../../sourceCode/EventHandler/IEvent.h \
    ../../sourceCode/EventHandler/IEventQueue.h \
    ../../sourceCode/EventHandler/ListEventQueue.h \
    ../../sourceCode/PlatformWrapper/NetworkHost.h \
    ../../sourceCode/PlatformWrapper/SocketWrapper.h \
    ../../sourceCode/PlatformWrapper/SocketWrapperDef.h \
    ../../sourceCode/PlatformWrapper/SystemApi.h \
    ../../sourceCode/PlatformWrapper/SystemErrorInfo.h \
    ../../sourceCode/ProcessManagement/ProcessManagementProcess.h

INCLUDEPATH += ../../sourceCode/Common \
               ../../sourceCode/PlatformWrapper \
               ../../sourceCode/TraceLog \
               ../../sourceCode/Configure \
               ../../sourceCode/Core \
               ../../sourceCode/TimerHandler \
               ../../sourceCode/Io \
               ../../sourceCode/EventHandler \
               ../../sourceCode/ProcessManagementSupport \



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../sourceCode/static_lib/ -lssh.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../sourceCode/static_lib/ -lssh.dll

LIBS += -lWs2_32
