QT += core
QT -= gui

CONFIG += c++11

TARGET = ProcessManagement
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ../../sourceCode/ProcessManagement/IUnixProcess.cpp \
    ../../sourceCode/ProcessManagement/UnixProcess.cpp \
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
    ../../sourceCode/ProcessManagement/Component.h \
    ../../sourceCode/ProcessManagement/IUnixProcess.h \
    ../../sourceCode/ProcessManagement/UnixProcess.h \
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
    ../../sourceCode/Configure/TraceLogConfigure.h

INCLUDEPATH += ../../sourceCode/Common \
               ../../sourceCode/TraceLog \
               ../../sourceCode/Configure \
DISTFILES += \
    ../../sourceCode/Common/CMakeLists.txt \
    ../../sourceCode/Configure/CMakeLists.txt
