QT += core
QT -= gui

CONFIG += c++11

TARGET = ClusterMessageTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../sourceCode/gtest/googletest/include \
               ../../sourceCode/gtest/googlemock/include \
               ../../sourceCode/gtest/googletest/ \
               ../../sourceCode/gtest/googlemock/ \
               ../../sourceCode/Serialize \
               ../../sourceCode/Common \
               ../../sourceCode/TraceLog \
               ../../sourceCode/Configure \
               ../../sourceCode/Network \
               ../../sourceCode/IoPlatformWrapper \
               ../../sourceCode/Environment \
               ../../sourceCode/IpcMessage \
               ../../sourceCode/Serialize \
               ../../sourceCode/ClusterMgtMessage

SOURCES += \
    ../../sourceCode/ClusterMgtMessageTest/ClusterMgtBrieflyResponseMessage.cpp \
    ../../sourceCode/ClusterMgtMessageTest/ClusterMgtMessageFactoryTest.cpp \
    ../../sourceCode/ClusterMgtMessage/ClusterMgtBrieflyResponse.cpp \
    ../../sourceCode/ClusterMgtMessage/ClusterMgtMessageFactory.cpp \
    ../../sourceCode/ClusterMgtMessage/IClusterMgtMessage.cpp \
    ../../sourceCode/Environment/ComputerNodeInfo.cpp \
    ../../sourceCode/Environment/CpuInfo.cpp \
    ../../sourceCode/Environment/CpuInfoBriefly.cpp \
    ../../sourceCode/Environment/CpuInfoDataType.cpp \
    ../../sourceCode/Environment/CpuUsage.cpp \
    ../../sourceCode/Environment/CpuUsageCalculator.cpp \
    ../../sourceCode/Environment/cpuusagedatatype.cpp \
    ../../sourceCode/Environment/CpuUsageInfo.cpp \
    ../../sourceCode/Environment/DiskUsageInfo.cpp \
    ../../sourceCode/Environment/EnvironmentSystemInfomation.cpp \
    ../../sourceCode/Environment/MemoryInfo.cpp \
    ../../sourceCode/Environment/MemoryInfoBriefly.cpp \
    ../../sourceCode/Environment/MemoryUsageInfo.cpp \
    ../../sourceCode/Environment/MemoryUsageInfoDataType.cpp \
    ../../sourceCode/Environment/MiscInfo.cpp \
    ../../sourceCode/Environment/NetworkInfo.cpp \
    ../../sourceCode/Environment/SystemInfoBriefly.cpp \
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
    ../../sourceCode/Configure/TraceLogConfigure.cpp \
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
    ../../sourceCode/IpcMessage/IIpcComunicationMessage.cpp \
    ../../sourceCode/IpcMessage/IIpcMessage.cpp \
    ../../sourceCode/IpcMessage/IIpcMessageFactory.cpp \
    ../../sourceCode/IpcMessage/IIpcMessageQueue.cpp \
    ../../sourceCode/IpcMessage/IpcAuthorizationRequest.cpp \
    ../../sourceCode/IpcMessage/IpcAuthorizationResponse.cpp \
    ../../sourceCode/IpcMessage/IpcHeartbeatReport.cpp \
    ../../sourceCode/IpcMessage/IpcLayerMessageFactory.cpp \
    ../../sourceCode/IpcMessage/IpcMessageIdGenerator.cpp \
    ../../sourceCode/IpcMessage/IpcMessageType.cpp \
    ../../sourceCode/IpcMessage/IpcThreadSafeMessageQueue.cpp \
    ../../sourceCode/Network/IpAddress.cpp \
    ../../sourceCode/Serialize/ISerializable.cpp \
    ../../sourceCode/Serialize/ReadBuffer.cpp \
    ../../sourceCode/Serialize/WriteBuffer.cpp \
    ../../sourceCode/ClusterMgtMessage/ClusterMgtBrieflyRequest.cpp \
    ../../sourceCode/IoPlatformWrapper/SocketWrapper.cpp \
    ../../sourceCode/IoPlatformWrapper/SystemErrorInfo.cpp \
    ../../sourceCode/Network/NetworkEnv.cpp \
    ../../sourceCode/Network/IpPort.cpp \
    ../../sourceCode/Network/IpSocketEndpoint.cpp

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
    ../../sourceCode/ClusterMgtMessage/ClusterMgtBrieflyResponse.h \
    ../../sourceCode/ClusterMgtMessage/ClusterMgtMessageFactory.h \
    ../../sourceCode/ClusterMgtMessage/Component.h \
    ../../sourceCode/ClusterMgtMessage/IClusterMgtMessage.h \
    ../../sourceCode/Environment/Component.h \
    ../../sourceCode/Environment/ComputerNodeInfo.h \
    ../../sourceCode/Environment/CpuInfo.h \
    ../../sourceCode/Environment/CpuInfoBriefly.h \
    ../../sourceCode/Environment/cpuinfodatatype.h \
    ../../sourceCode/Environment/CpuUsage.h \
    ../../sourceCode/Environment/CpuUsageCalculator.h \
    ../../sourceCode/Environment/CpuUsageDataType.h \
    ../../sourceCode/Environment/CpuUsageInfo.h \
    ../../sourceCode/Environment/DiskUsageInfo.h \
    ../../sourceCode/Environment/EnvironmentSystemInfomation.h \
    ../../sourceCode/Environment/MemoryInfo.h \
    ../../sourceCode/Environment/MemoryInfoBriefly.h \
    ../../sourceCode/Environment/MemoryUsageInfo.h \
    ../../sourceCode/Environment/MemoryUsageInfoDataType.h \
    ../../sourceCode/Environment/MiscInfo.h \
    ../../sourceCode/Environment/NetworkInfo.h \
    ../../sourceCode/Environment/SystemInfoBriefly.h \
    ../../sourceCode/Common/App.h \
    ../../sourceCode/Common/AppConst.h \
    ../../sourceCode/Common/FilePathHandler.h \
    ../../sourceCode/Common/generic.h \
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
    ../../sourceCode/Configure/Configure.h \
    ../../sourceCode/Configure/Configure_Define.h \
    ../../sourceCode/Configure/ExceptionConfigure.h \
    ../../sourceCode/Configure/TraceLogConfigure.h \
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
    ../../sourceCode/IoPlatformWrapper/SocketWrapper.h \
    ../../sourceCode/IoPlatformWrapper/SocketWrapperDef.h \
    ../../sourceCode/IoPlatformWrapper/SystemErrorInfo.h \
    ../../sourceCode/IpcMessage/IIpcComunicationMessage.h \
    ../../sourceCode/IpcMessage/IIpcMessage.h \
    ../../sourceCode/IpcMessage/IIpcMessageFactory.h \
    ../../sourceCode/IpcMessage/IIpcMessageQueue.h \
    ../../sourceCode/IpcMessage/IpcAuthorizationRequest.h \
    ../../sourceCode/IpcMessage/IpcAuthorizationResponse.h \
    ../../sourceCode/IpcMessage/IpcHeartbeatReport.h \
    ../../sourceCode/IpcMessage/IpcLayerMessageFactory.h \
    ../../sourceCode/IpcMessage/IpcMessageIdGenerator.h \
    ../../sourceCode/IpcMessage/IpcMessageType.h \
    ../../sourceCode/IpcMessage/IpcThreadSafeMessageQueue.h \
    ../../sourceCode/Network/IpAddress.h \
    ../../sourceCode/Serialize/BufferToData.h \
    ../../sourceCode/Serialize/Component.h \
    ../../sourceCode/Serialize/DataToBuffer.h \
    ../../sourceCode/Serialize/ISerializable.h \
    ../../sourceCode/Serialize/ReadBuffer.h \
    ../../sourceCode/Serialize/WriteBuffer.h \
    ../../sourceCode/TraceLog/Trace.h \
    ../../sourceCode/TraceLog/TraceBuf.h \
    ../../sourceCode/TraceLog/TraceConsole.h \
    ../../sourceCode/TraceLog/TraceFile.h \
    ../../sourceCode/ClusterMgtMessage/ClusterMgtBrieflyRequest.h \
    ../../sourceCode/Network/NetworkEnv.h \
    ../../sourceCode/Network/Component.h \
    ../../sourceCode/Network/IpPort.h \
    ../../sourceCode/Network/IpSocketEndpoint.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../sourceCode/static_lib/ -lssh.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../sourceCode/static_lib/ -lssh.dll

LIBS += -lWs2_32
