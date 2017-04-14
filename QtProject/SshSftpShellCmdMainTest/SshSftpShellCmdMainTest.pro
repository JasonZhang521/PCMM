QT += core
QT -= gui

CONFIG += c++11

TARGET = SshSftpShellCmdMainTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../sourceCode/Common/ \
               ../../sourceCode/Configure/ \
               ../../sourceCode/SshWrapper/ \
               ../../sourceCode/TraceLog/ \
               ../../sourceCode/include

SOURCES += \
    ../../sourceCode/Common/FilePathHandler.cpp \
    ../../sourceCode/Common/LocalTime.cpp \
    ../../sourceCode/Common/remove_character.cpp \
    ../../sourceCode/Common/replace_character.cpp \
    ../../sourceCode/Configure/Configure.cpp \
    ../../sourceCode/Configure/ExceptionConfigure.cpp \
    ../../sourceCode/Configure/TraceLogConfigure.cpp \
    ../../sourceCode/SshWrapper/SshClient.cpp \
    ../../sourceCode/SshWrapper/SshClientSession.cpp \
    ../../sourceCode/SshWrapper/SshFtpSession.cpp \
    ../../sourceCode/SshWrapper/SshInteractiveShellChannel.cpp \
    ../../sourceCode/SshWrapper/SshShellChannel.cpp \
    ../../sourceCode/SshWrapperTest/SshSftpShellCmdMainTest.cpp \
    ../../sourceCode/SshWrapper/SftpDirAttribute.cpp

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
    ../../sourceCode/Common/FilePathHandler.h \
    ../../sourceCode/Common/LocalTime.h \
    ../../sourceCode/Common/remove_character.h \
    ../../sourceCode/Common/replace_character.h \
    ../../sourceCode/Configure/Configure.h \
    ../../sourceCode/Configure/Configure_Define.h \
    ../../sourceCode/Configure/ExceptionConfigure.h \
    ../../sourceCode/Configure/TraceLogConfigure.h \
    ../../sourceCode/include/libssh/callbacks.h \
    ../../sourceCode/include/libssh/legacy.h \
    ../../sourceCode/include/libssh/libssh.h \
    ../../sourceCode/include/libssh/libsshpp.hpp \
    ../../sourceCode/include/libssh/server.h \
    ../../sourceCode/include/libssh/sftp.h \
    ../../sourceCode/include/libssh/ssh2.h \
    ../../sourceCode/SshWrapper/ISshClient.h \
    ../../sourceCode/SshWrapper/ISshClientSession.h \
    ../../sourceCode/SshWrapper/ISshFtpSession.h \
    ../../sourceCode/SshWrapper/ISshShellChannel.h \
    ../../sourceCode/SshWrapper/SshClient.h \
    ../../sourceCode/SshWrapper/SshClientSession.h \
    ../../sourceCode/SshWrapper/SshConfigure.h \
    ../../sourceCode/SshWrapper/SshFtpSession.h \
    ../../sourceCode/SshWrapper/SshInteractiveShellChannel.h \
    ../../sourceCode/SshWrapper/SshShellChannel.h \
    ../../sourceCode/TraceLog/Trace.h \
    ../../sourceCode/TraceLog/TraceBuf.h \
    ../../sourceCode/TraceLog/TraceConsole.h \
    ../../sourceCode/TraceLog/TraceFile.h \
    ../../sourceCode/Common/Macro.h \
    ../../sourceCode/SshWrapper/Componet.h \
    ../../sourceCode/SshWrapper/SftpDirAttribute.h \
    ../../sourceCode/SshWrapper/Component.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../sourceCode/static_lib/ -lssh.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../sourceCode/static_lib/ -lssh.dll

INCLUDEPATH += $$PWD/../../sourceCode/static_lib
DEPENDPATH += $$PWD/../../sourceCode/static_lib
DLLDESTDIR += $$PWD/../../sourceCode/dynamic_lib/ssh
