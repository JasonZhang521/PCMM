QT += core
QT -= gui

CONFIG += c++11

TARGET = TimeControl
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../sourceCode/TimeHandler
INCLUDEPATH += ../../sourceCode/EventHandler
INCLUDEPATH += ../../sourceCode/Common
INCLUDEPATH += ../../sourceCode/TraceLog
INCLUDEPATH += ../../sourceCode/Configure

SOURCES += main.cpp \
    ../../sourceCode/TimeHandler/SystemTime.cpp \
    ../../sourceCode/TimeHandler/ITimer.cpp \
    ../../sourceCode/EventHandler/IEvent.cpp \
    ../../sourceCode/TimeHandler/EventTimer.cpp \
    ../../sourceCode/TimeHandler/TimeStat.cpp \
    ../../sourceCode/TimeHandler/ITimerQueue.cpp \
    ../../sourceCode/TimeHandler/TimerIdGenerator.cpp \
    ../../sourceCode/TimeHandler/ListTimerQueue.cpp \
    ../../sourceCode/Common/FilePathHandler.cpp \
    ../../sourceCode/Common/LocalTime.cpp \
    ../../sourceCode/Common/remove_character.cpp \
    ../../sourceCode/Common/replace_character.cpp \
    ../../sourceCode/Configure/Configure.cpp \
    ../../sourceCode/Configure/ExceptionConfigure.cpp \
    ../../sourceCode/Configure/TraceLogConfigure.cpp

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
    ../../sourceCode/TimeHandler/SystemTime.h \
    ../../sourceCode/TimeHandler/ITimer.h \
    ../../sourceCode/EventHandler/IEvent.h \
    ../../sourceCode/TimeHandler/EventTimer.h \
    ../../sourceCode/TimeHandler/TimeStat.h \
    ../../sourceCode/TimeHandler/ITimerQueue.h \
    ../../sourceCode/TimeHandler/TimerIdGenerator.h \
    ../../sourceCode/TimeHandler/ListTimerQueue.h \
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
    ../../sourceCode/TimeHandler/Component.h \
    ../../sourceCode/Common/AppConst.h \
    ../../sourceCode/Configure/Configure.h \
    ../../sourceCode/Configure/Configure_Define.h \
    ../../sourceCode/Configure/ExceptionConfigure.h \
    ../../sourceCode/Configure/TraceLogConfigure.h
