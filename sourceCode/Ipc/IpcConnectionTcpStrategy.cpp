#include "IpcConnectionTcpStrategy.h"
#include "ITcpClient.h"
#include "ITcpServer.h"
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
                         std::shared_ptr<Network::ITcpClient> client,
                         std::shared_ptr<Network::ITcpServer> server)
: type_(type)
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

void IpcConnectionTcpStrategy::send(Serialize::WriteBuffer& writeBuffer)
{
    TRACE_DEBUG("type = " << IpcConnectionTypeString(type_));
    if (type_ == IpcConnectionType::IpcConnection_Client)
    {
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

}
