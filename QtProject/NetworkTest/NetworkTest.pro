QT += core
QT -= gui

CONFIG += c++11

TARGET = NetworkTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../sourceCode/Serialize \
               ../../sourceCode/Common \
               ../../sourceCode/TraceLog \
               ../../sourceCode/Configure \
               ../../sourceCode/EventHandler \
               ../../sourceCode/TimeHandler \
               ../../sourceCode/Network \
               ../../sourceCode/IoPlatformWrapper \
               ../../sourceCode/Connection \
               ../../sourceCode/Environment \
               ../../sourceCode/gtest/googletest/include \
               ../../sourceCode/gtest/googlemock/include \
               ../../sourceCode/gtest/googletest/ \
               ../../sourceCode/gtest/googlemock/

SOURCES += \
    ../../sourceCode/Network/IpAddress.cpp \
    ../../sourceCode/Network/ITcpClient.cpp \
    ../../sourceCode/Serialize/ISerializable.cpp \
    ../../sourceCode/Serialize/ReadBuffer.cpp \
    ../../sourceCode/Serialize/WriteBuffer.cpp \
    ../../sourceCode/Network/IpPort.cpp \
    ../../sourceCode/Common/FilePathHandler.cpp \
    ../../sourceCode/Common/LocalTime.cpp \
    ../../sourceCode/Common/Random.cpp \
    ../../sourceCode/Common/remove_character.cpp \
    ../../sourceCode/Common/replace_character.cpp \
    ../../sourceCode/Network/IpSocketEndpoint.cpp \
    ../../sourceCode/Configure/Configure.cpp \
    ../../sourceCode/Configure/ExceptionConfigure.cpp \
    ../../sourceCode/Configure/TraceLogConfigure.cpp \
    ../../sourceCode/Network/TcpSocket.cpp \
    ../../sourceCode/Network/SocketImp.cpp \
    ../../sourceCode/Network/TcpClient.cpp \
    ../../sourceCode/EventHandler/IEvent.cpp \
    ../../sourceCode/Network/ITcpServer.cpp \
    ../../sourceCode/Network/TcpServer.cpp \
    ../../sourceCode/EventHandler/IEventQueue.cpp \
    ../../sourceCode/EventHandler/EventIdGenerator.cpp \
    ../../sourceCode/EventHandler/ListEventQueue.cpp \
    ../../sourceCode/Common/SystemTime.cpp \
    ../../sourceCode/Common/TimeStat.cpp \
    ../../sourceCode/NetworkTest/IpPortTest.cpp \
    ../../sourceCode/gtest/googlemock/src/gmock-all.cc \
    ../../sourceCode/gtest/googlemock/src/gmock-cardinalities.cc \
    ../../sourceCode/gtest/googlemock/src/gmock-internal-utils.cc \
    ../../sourceCode/gtest/googlemock/src/gmock-matchers.cc \
    ../../sourceCode/gtest/googlemock/src/gmock-spec-builders.cc \
    ../../sourceCode/gtest/googlemock/src/gmock.cc \
    ../../sourceCode/gtest/googletest/src/gtest-all.cc \
    ../../sourceCode/gtest/googletest/src/gtest-death-test.cc \
    ../../sourceCode/gtest/googletest/src/gtest-filepath.cc \
    ../../sourceCode/gtest/googletest/src/gtest-port.cc \
    ../../sourceCode/gtest/googletest/src/gtest-printers.cc \
    ../../sourceCode/gtest/googletest/src/gtest-test-part.cc \
    ../../sourceCode/gtest/googletest/src/gtest-typed-test.cc \
    ../../sourceCode/gtest/googletest/src/gtest.cc \
    ../../sourceCode/gtest/googletest/src/gtest_main.cc \
    ../../sourceCode/NetworkTest/IpAddressTest.cpp \
    ../../sourceCode/Io/IIoControl.cpp \
    ../../sourceCode/Io/IoControlEvent.cpp \
    ../../sourceCode/IpcMessage/IIpcMessage.cpp \
    ../../sourceCode/IpcMessage/IpcMessageIdGenerator.cpp \
    ../../sourceCode/Connection/IConnectionTx.cpp \
    ../../sourceCode/Connection/IConnectionRx.cpp \
    ../../sourceCode/Ipc/IpcClient.cpp \
    ../../sourceCode/Ipc/IpcConnectionTcpStrategy.cpp \
    ../../sourceCode/Ipc/IIpcConnectionClientStrategy.cpp \
    ../../sourceCode/Environment/CpuUsageCalculator.cpp \
    ../../sourceCode/Environment/CpuUsage.cpp \
    ../../sourceCode/IoPlatformWrapper/SocketWrapper.cpp \
    ../../sourceCode/Environment/CpuUsageInfo.cpp

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
    ../../sourceCode/Network/IpAddress.h \
    ../../sourceCode/Network/ITcpClient.h \
    ../../sourceCode/Serialize/BufferToData.h \
    ../../sourceCode/Serialize/DataToBuffer.h \
    ../../sourceCode/Serialize/ISerializable.h \
    ../../sourceCode/Serialize/ReadBuffer.h \
    ../../sourceCode/Serialize/WriteBuffer.h \
    ../../sourceCode/Network/IpPort.h \
    ../../sourceCode/Common/App.h \
    ../../sourceCode/Common/FilePathHandler.h \
    ../../sourceCode/Common/LocalTime.h \
    ../../sourceCode/Common/Macro.h \
    ../../sourceCode/Common/Random.h \
    ../../sourceCode/Common/remove_character.h \
    ../../sourceCode/Common/replace_character.h \
    ../../sourceCode/Common/Generic.h \
    ../../sourceCode/Network/IpSocketEndpoint.h \
    ../../sourceCode/TraceLog/Trace.h \
    ../../sourceCode/TraceLog/TraceBuf.h \
    ../../sourceCode/TraceLog/TraceConsole.h \
    ../../sourceCode/TraceLog/TraceFile.h \
    ../../sourceCode/Configure/Configure.h \
    ../../sourceCode/Configure/Configure_Define.h \
    ../../sourceCode/Configure/ExceptionConfigure.h \
    ../../sourceCode/Configure/TraceLogConfigure.h \
    ../../sourceCode/Network/Component.h \
    ../../sourceCode/Common/AppConst.h \
    ../../sourceCode/Network/TcpSocket.h \
    ../../sourceCode/Network/SocketImp.h \
    ../../sourceCode/Network/TcpClient.h \
    ../../sourceCode/EventHandler/IEvent.h \
    ../../sourceCode/Network/TcpState.h \
    ../../sourceCode/Network/ITcpServer.h \
    ../../sourceCode/Network/TcpResult.h \
    ../../sourceCode/Network/TcpServer.h \
    ../../sourceCode/EventHandler/IEventQueue.h \
    ../../sourceCode/EventHandler/EventIdGenerator.h \
    ../../sourceCode/EventHandler/ListEventQueue.h \
    ../../sourceCode/EventHandler/Component.h \
    ../../sourceCode/Common/SystemTime.h \
    ../../sourceCode/Common/TimeStat.h \
    ../../sourceCode/gtest/googlemock/include/gmock/internal/custom/gmock-generated-actions.h \
    ../../sourceCode/gtest/googlemock/include/gmock/internal/custom/gmock-matchers.h \
    ../../sourceCode/gtest/googlemock/include/gmock/internal/custom/gmock-port.h \
    ../../sourceCode/gtest/googlemock/include/gmock/internal/gmock-generated-internal-utils.h \
    ../../sourceCode/gtest/googlemock/include/gmock/internal/gmock-internal-utils.h \
    ../../sourceCode/gtest/googlemock/include/gmock/internal/gmock-port.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-actions.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-cardinalities.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-generated-actions.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-generated-function-mockers.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-generated-matchers.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-generated-nice-strict.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-matchers.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-more-actions.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-more-matchers.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-spec-builders.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/custom/gtest-port.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/custom/gtest-printers.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/custom/gtest.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-death-test-internal.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-filepath.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-internal.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-linked_ptr.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-param-util-generated.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-param-util.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-port-arch.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-port.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-string.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-tuple.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-type-util.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest-death-test.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest-message.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest-param-test.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest-printers.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest-spi.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest-test-part.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest-typed-test.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest_pred_impl.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest_prod.h \
    ../../sourceCode/gtest/googletest/src/gtest-internal-inl.h \
    ../../sourceCode/Io/IIoControl.h \
    ../../sourceCode/Io/IoControlEvent.h \
    ../../sourceCode/Io/Component.h \
    ../../sourceCode/IpcMessage/IIpcMessage.h \
    ../../sourceCode/IpcMessage/IpcMessageType.h \
    ../../sourceCode/IpcMessage/IpcMessageIdGenerator.h \
    ../../sourceCode/Connection/IConnectionTx.h \
    ../../sourceCode/Connection/IConnectionRx.h \
    ../../sourceCode/Ipc/IpcClient.h \
    ../../sourceCode/Ipc/IpcConnectionTcpStrategy.h \
    ../../sourceCode/Ipc/Component.h \
    ../../sourceCode/Ipc/IIpcConnectionClientStrategy.h \
    ../../sourceCode/Environment/CpuUsageCalculator.h \
    ../../sourceCode/Environment/CpuUsageDataType.h \
    ../../sourceCode/Environment/CpuUsage.h \
    ../../sourceCode/Common/Operator.h \
    ../../sourceCode/Environment/Component.h \
    ../../sourceCode/IoPlatformWrapper/SocketWrapper.h \
    ../../sourceCode/IoPlatformWrapper/SocketWrapperDef.h \
    ../../sourceCode/Environment/CpuUsageInfo.h



LIBS += -lWs2_32
