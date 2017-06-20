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
                                                   IpcMessageFactroyMap ipcMessageFactories,
                                                   std::shared_ptr<Network::ITcpClient> client)
: connectionReceiver_(connectionReceiver)
, ipcMessageFactories_(ipcMessageFactories)
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

void IpcConnectionTcpClientStrategy::addIpcMessageFactory(IpcMessage::IpcMessageType ipcMessageType,
                                  std::shared_ptr<IpcMessage::IIpcMessageFactory> factory)
{
    ipcMessageFactories_[ipcMessageType] = factory;
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

    IpcMessageFactroyMap::iterator
            it = ipcMessageFactories_.find(static_cast<IpcMessage::IpcMessageType>(messageType));
    if (it != ipcMessageFactories_.end())
    {
        std::shared_ptr<IpcMessage::IIpcMessageFactory>& factory = it->second;
        uint8_t ipcApplicationType = 0xff;
        readBuffer.peek(ipcApplicationType);
        std::unique_ptr<IpcMessage::IIpcMessage> msg(factory->createMessage(ipcApplicationType));
        if (msg)
        {
            connectionReceiver_->onReceive(std::move(msg));
        }
        else
        {
            TRACE_WARNING("Recieve error message, wrong application type = "
                          << static_cast<int>(ipcApplicationType)
                          << ", for ipc type = "
                          << static_cast<int>(messageType));
        }
    }
    else
    {
        TRACE_WARNING("Recieve error message, wrong ipc message type = "
                      << static_cast<int>(messageType));
    }
}

void IpcConnectionTcpClientStrategy::onDisconnect()
{
    TRACE_ENTER();
    connectionReceiver_->onDisconnect();
}

}
