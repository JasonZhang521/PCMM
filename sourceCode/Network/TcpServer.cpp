#include "TcpServer.h"
#include "Trace.h"

namespace Network {

TcpServer::TcpServer(const IpSocketEndpoint& localEndpoint)
    :socket_(localEndpoint)
    ,state_(TcpState::Tcp_Closed)
{
}

TcpServer::~TcpServer()
{
}

TcpResult TcpServer::init()
{
    TRACE_ENTER();
    socket_.init();
    return TcpResult::Success;
}

TcpResult TcpServer::listen(int backlog)
{
    TRACE_ENTER();
    int ret = socket_.listen(backlog);
    if (SOCKET_ERROR == ret)
    {
        TRACE_WARNING(socket_.getErrorInfo());
        return TcpResult::Failed;
    }
    else
    {
        return TcpResult::Success;
    }
}

TcpResult TcpServer::accept(int flag)
{
    TRACE_ENTER();
    IpSocketEndpoint remoteEndPoint;
    int fd = socket_.accept(remoteEndPoint, flag);
    if (SOCKET_ERROR == fd)
    {
        TRACE_WARNING(socket_.getErrorInfo());
        return TcpResult::Failed;
    }
    else
    {
        return TcpResult::Success;
    }
}

TcpResult TcpServer::disconnect()
{
    TRACE_ENTER();
    if (SOCKET_ERROR == socket_.close())
    {
        TRACE_NOTICE(socket_.getErrorInfo());
        return TcpResult::Failed;
    }
    else
    {
        return TcpResult::Success;
    }
}

TcpResult TcpServer::cleanup()
{
    TRACE_ENTER();
    if (SOCKET_ERROR == socket_.shutdown(SOCKET_SD_BOTH))
    {
        TRACE_NOTICE(socket_.getErrorInfo());
        return TcpResult::Failed;
    }
    else
    {
        return TcpResult::Success;
    }
}

void TcpServer::run(EventHandler::EventFlag flag)
{
    static_cast<void>(flag);
}

}
