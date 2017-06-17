#include "IpcConnectionTcpStrategy.h"
#include "IIpcConnectionReceiver.h"
#include "ITcpClient.h"
#include "ITcpServer.h"
#include "IIpcMessage.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "Trace.h"
#include "App.h"

namespace Ipc {


std::string IpcConnectionTypeString(IpcConnectionType type)
{
    switch (type) {
    case IpcConnectionType::IpcConnection_Client:
        return std::string("Ipc Client");
    case IpcConnectionType::IpcConnection_Server:
        return std::string("Ipc Server");
    default:
        return std::string("");
    }
}

IpcConnectionTcpStrategy::IpcConnectionTcpStrategy(IpcConnectionType type,
                                                   std::shared_ptr<IIpcConnectionReceiver> connectionReceiver,
                                                   std::shared_ptr<IpcMessage::IIpcMessageFactory> ipcMessageFactory,
                                                   std::shared_ptr<Network::ITcpClient> client,
                                                   std::shared_ptr<Network::ITcpServer> server)
: type_(type)
, connectionReceiver_(connectionReceiver)
, ipcMessageFactory_(ipcMessageFactory)
, client_(client)
, server_(server)
{
    if (type_ == IpcConnectionType::IpcConnection_Client)
    {
        if (!client_)
        {
            TRACE_ERROR("null Ipc client");
            App::ExitWithCoredump();
        }
        client_->init();
    }
    else if (type_ == IpcConnectionType::IpcConnection_Server)
    {
        if (!server_)
        {
            TRACE_ERROR("null Ipc server");
            App::ExitWithCoredump();
        }
    }
}


IpcConnectionTcpStrategy::~IpcConnectionTcpStrategy()
{

}

void IpcConnectionTcpStrategy::connect()
{
    TRACE_DEBUG("type = " << IpcConnectionTypeString(type_));
    if (type_ == IpcConnectionType::IpcConnection_Client)
    {
        client_->connect();
    }
}

void IpcConnectionTcpStrategy::send(const IpcMessage::IIpcMessage& msg)
{
    TRACE_DEBUG("type = " << IpcConnectionTypeString(type_));
    if (type_ == IpcConnectionType::IpcConnection_Client)
    {
        Serialize::WriteBuffer writeBuffer;
        msg.serialize(writeBuffer);
        client_->send(writeBuffer);
    }
}

void IpcConnectionTcpStrategy::disconnect()
{
    TRACE_DEBUG("type = " << IpcConnectionTypeString(type_));
    if (type_ == IpcConnectionType::IpcConnection_Client)
    {
        client_->disconnect();
        client_->cleanup();
    }
}

void IpcConnectionTcpStrategy::onConnect()
{
    connectionReceiver_->onConnect();
}

void IpcConnectionTcpStrategy::onReceive(Serialize::ReadBuffer& readBuffer)
{
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
}

void IpcConnectionTcpStrategy::onDisconnect()
{
    connectionReceiver_->onDisconnect();
}

}
