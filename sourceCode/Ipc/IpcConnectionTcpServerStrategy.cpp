#include "IpcConnectionTcpServerStrategy.h"
#include "IIpcConnectionAcceptor.h"
#include "ITcpServer.h"
#include "Trace.h"

namespace Ipc {
IpcConnectionTcpServerStrategy::IpcConnectionTcpServerStrategy(std::shared_ptr<IIpcConnectionAcceptor> connectionAcceptor,
                                                               std::shared_ptr<Network::ITcpServer> server)
    :connectionAcceptor_(connectionAcceptor)
    ,server_(server)
{
    if (!server_)
    {
        TRACE_ERROR("null Ipc server");
        throw std::invalid_argument("null Ipc server!");
    }
}

IpcConnectionTcpServerStrategy::IpcConnectionTcpServerStrategy(std::shared_ptr<Network::ITcpServer> server)
    :server_(server)
{
    if (!server_)
    {
        TRACE_ERROR("null Ipc server");
        throw std::invalid_argument("null Ipc server!");
    }
}

IpcConnectionTcpServerStrategy::~IpcConnectionTcpServerStrategy()
{

}

void IpcConnectionTcpServerStrategy::startup()
{
    server_->bind();
    int backlog = 0;
    server_->listen(backlog);
}

void IpcConnectionTcpServerStrategy::shutdown()
{

}

void IpcConnectionTcpServerStrategy::onAccept(int fd,
                      const Network::IpSocketEndpoint& localEndPoint,
                      const Network::IpSocketEndpoint& remoteEndPoint)
{
    connectionAcceptor_->onAccept(fd, localEndPoint, remoteEndPoint);
}

void  IpcConnectionTcpServerStrategy::setIpcConnectionAcceptor(std::shared_ptr<IIpcConnectionAcceptor> acceptor)
{
    connectionAcceptor_ = acceptor;
}


}
