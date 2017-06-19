#include "IpcConnectionTcpClientStrategy.h"
#include "IIpcConnectionReceiver.h"
#include "ITcpClient.h"
#include "IIpcMessage.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "Trace.h"
#include "App.h"

namespace Ipc {

IpcConnectionTcpClientStrategy::IpcConnectionTcpClientStrategy(
                                                   std::shared_ptr<IIpcConnectionReceiver> connectionReceiver,
                                                   std::shared_ptr<IpcMessage::IIpcMessageFactory> ipcMessageFactory,
                                                   std::shared_ptr<Network::ITcpClient> client)
: connectionReceiver_(connectionReceiver)
, ipcMessageFactory_(ipcMessageFactory)
, client_(client)
{
    if (!client_)
    {
        TRACE_ERROR("null Ipc client");
        throw std::invalid_argument("null Ipc client!");
    }
    client_->init();
}

IpcConnectionTcpClientStrategy::IpcConnectionTcpClientStrategy(
                                                   std::shared_ptr<Network::ITcpClient> client)
    : client_(client)
{
    if (!client_)
    {
        TRACE_ERROR("null Ipc client");
        throw std::invalid_argument("null Ipc client!");
    }
    client_->init();
}

IpcConnectionTcpClientStrategy::~IpcConnectionTcpClientStrategy()
{

}

void IpcConnectionTcpClientStrategy::connect()
{
    TRACE_ENTER();
    client_->connect();
}

void IpcConnectionTcpClientStrategy::send(const IpcMessage::IIpcMessage& msg)
{
    TRACE_ENTER();
    Serialize::WriteBuffer writeBuffer;
    msg.serialize(writeBuffer);
    client_->send(writeBuffer);
}

void IpcConnectionTcpClientStrategy::disconnect()
{
    TRACE_ENTER();
    client_->disconnect();
    client_->cleanup();
}

void IpcConnectionTcpClientStrategy::setIpcConnectionReceiver(std::shared_ptr<IIpcConnectionReceiver> receiver)
{
    TRACE_ENTER();
    connectionReceiver_ = receiver;
}

void IpcConnectionTcpClientStrategy::setIpcMessageFactory(std::shared_ptr<IpcMessage::IIpcMessageFactory> factory)
{
    TRACE_ENTER();
    ipcMessageFactory_ = factory;
}

void IpcConnectionTcpClientStrategy::onConnect()
{
    TRACE_ENTER();
    connectionReceiver_->onConnect();
}

void IpcConnectionTcpClientStrategy::onReceive(Serialize::ReadBuffer& readBuffer)
{
    TRACE_ENTER();
    uint8_t messageType = static_cast<uint8_t>(IpcMessage::IpcMessage_None);
    readBuffer.peek(messageType);
    uint8_t monitorType = 0xff;
    readBuffer.peek(monitorType);

    const bool isIpcMessage = (messageType != IpcMessage::IpcMessage_SystemMonitor);
    const bool isMonitorType = (monitorType == IpcMessage::MonitorMessage ||
                                monitorType == IpcMessage::MonitorRequest);
    if (isIpcMessage && isMonitorType)
    {
        std::unique_ptr<IpcMessage::IIpcMessage> msg(ipcMessageFactory_->createMessage(monitorType));
        connectionReceiver_->onReceive(std::move(msg));
    }
    else
    {
        TRACE_WARNING("receive unsupport Message! message type = " << static_cast<int>(messageType)
                      << ", monitor type = " << static_cast<int>(monitorType));
    }
}

void IpcConnectionTcpClientStrategy::onDisconnect()
{
    TRACE_ENTER();
    connectionReceiver_->onDisconnect();
}

}
