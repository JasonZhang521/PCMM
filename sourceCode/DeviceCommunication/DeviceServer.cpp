#include "DeviceServer.h"
#include "DeviceConnectionAcceptor.h"
#include "ITcpServer.h"
#include "IpSocketEndpoint.h"
#include "Component.h"
#include "Macro.h"
#include "Trace.h"

namespace DeviceCommunication {

GETCLASSNAME(DeviceServer)

DeviceServer::DeviceServer(DeviceType type, std::unique_ptr<Network::ITcpServer> server)
    : type_(type)
    , server_(std::move(server))
{

}

DeviceServer::~DeviceServer()
{

}

void DeviceServer::startup()
{
    TRACE_NOTICE("Tcp server init!");
    server_->init();
    TRACE_NOTICE("Tcp server bind!");
    server_->bind();
    int backlog = SOMAXCONN;
    TRACE_NOTICE("Tcp server start to listen!");
    server_->listen(backlog);
}

void DeviceServer::shutdown()
{
    TRACE_NOTICE("Tcp server shutdown!");
    server_->disconnect();
    server_->cleanup();
}

}
