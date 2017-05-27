QT += core
QT -= gui

CONFIG += c++11

TARGET = TimerControl
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../sourceCode/TimerHandler
INCLUDEPATH += ../../sourceCode/EventHandler
INCLUDEPATH += ../../sourceCode/Common
INCLUDEPATH += ../../sourceCode/TraceLog
INCLUDEPATH += ../../sourceCode/Configure

SOURCES += ../../sourceCode/EventHandler/IEvent.cpp \
    ../../sourceCode/TimerHandler/ITimer.cpp \
    ../../sourceCode/TimerHandler/EventTimer.cpp \
    ../../sourceCode/TimerHandler/ITimerQueue.cpp \
    ../../sourceCode/TimerHandler/TimerIdGenerator.cpp \
    ../../sourceCode/TimerHandler/ListTimerQueue.cpp \
    ../../sourceCode/Common/FilePathHandler.cpp \
    ../../sourceCode/Common/LocalTime.cpp \
    ../../sourceCode/Common/remove_character.cpp \
    ../../sourceCode/Common/replace_character.cpp \
    ../../sourceCode/Configure/Configure.cpp \
    ../../sourceCode/Configure/ExceptionConfigure.cpp \
    ../../sourceCode/Configure/TraceLogConfigure.cpp \
    ../../sourceCode/Common/Random.cpp \
    ../../sourceCode/Common/SystemTime.cpp \
    ../../sourceCode/Common/TimeStat.cpp

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
    ../../sourceCode/EventHandler/IEvent.h \
    ../../sourceCode/TraceLog/Trace.h \
    ../../sourceCode/TraceLog/TraceBuf.h \
    ../../sourceCode/TraceLog/TraceConsole.h \
    ../../sourceCode/TraceLog/TraceFile.h \
    ../../sourceCode/Common/App.h \
    ../../sourceCode/Common/FilePathHandler.h \
    ../../sourceCode/Common/LocalTime.h \
    ../../sourceCode/Common/Macro.h \
    ../../sourceCode/Common/remove_character.h \
    ../../sourceCode/Common/replace_character.h \
    ../../sourceCode/Common/AppConst.h \
    ../../sourceCode/Configure/Configure.h \
    ../../sourceCode/Configure/Configure_Define.h \
    ../../sourceCode/Configure/ExceptionConfigure.h \
    ../../sourceCode/Configure/TraceLogConfigure.h \
    ../../sourceCode/TimerHandler/Component.h \
    ../../sourceCode/TimerHandler/EventTimer.h \
    ../../sourceCode/TimerHandler/ITimer.h \
    ../../sourceCode/TimerHandler/ITimerQueue.h \
    ../../sourceCode/TimerHandler/ListTimerQueue.h \
    ../../sourceCode/TimerHandler/TimerIdGenerator.h \
    ../../sourceCode/Common/generic.h \
    ../../sourceCode/Common/Random.h \
    ../../sourceCode/Common/SystemTime.h \
    ../../sourceCode/Common/TimeStat.h
