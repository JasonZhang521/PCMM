#include "TcpClient.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "Trace.h"

namespace Network {

TcpClient::TcpClient(const IpSocketEndpoint& localEndpoint, const IpSocketEndpoint& remoteEndpoint)
    :socket_(localEndpoint, remoteEndpoint)
    ,state_(TcpState::Tcp_Closed)
{
}

TcpClient::~TcpClient()
{
}

TcpClientResult TcpClient::init()
{
    socket_.init();
    return TcpClientResult::Success;
}

TcpClientResult TcpClient::connect()
{
    TRACE_DEBUG("localEndpoint:" << socket_.getLocalEndpoint() << ", remoteEndpoint:" << remoteEndpoint);

    int ret = socket_.connect();

    if (SOCKET_ERROR == ret)
    {
        if (SOCKET_EINPROGRESS == socket_.getErrorNo())
        {
            TRACE_NOTICE(socket_.getErrorInfo());
            state_ = TcpState::Tcp_Connecting;
            return TcpClientResult::Success;
        }
        else
        {
            TRACE_WARNING(socket_.getErrorInfo());
            return TcpClientResult::Failed;
        }
    }
    else
    {
        return TcpClientResult::Success;
    }
}

TcpClientResult TcpClient::send(const Serialize::WriteBuffer& buffer)
{
    TRACE_ENTER();
    if (SOCKET_ERROR == socket_.send(buffer.getBuffer(), buffer.getDataSize(), SOCKET_FLAG_NONE))
    {
        TRACE_NOTICE(socket_.getErrorInfo());
        return TcpClientResult::Failed;
    }
    else
    {
        return TcpClientResult::Success;
    }
}

TcpClientResult TcpClient::receive(Serialize::ReadBuffer& buffer)
{
    TRACE_ENTER();
    if (SOCKET_ERROR == socket_.recv(buffer.getBuffer(), buffer.getBufferSize(), SOCKET_FLAG_NONE))
    {
        TRACE_NOTICE(socket_.getErrorInfo());
        return TcpClientResult::Failed;
    }
    else
    {
        return TcpClientResult::Success;
    }
}

TcpClientResult TcpClient::disconnect()
{
    TRACE_ENTER();
    if (SOCKET_ERROR == socket_.close())
    {
        TRACE_NOTICE(socket_.getErrorInfo());
        return TcpClientResult::Failed;
    }
    else
    {
        return TcpClientResult::Success;
    }
}

TcpClientResult TcpClient::cleanup()
{
    TRACE_ENTER();
    if (SOCKET_ERROR == socket_.shutdown(SOCKET_SD_BOTH))
    {
        TRACE_NOTICE(socket_.getErrorInfo());
        return TcpClientResult::Failed;
    }
    else
    {
        return TcpClientResult::Success;
    }
}

void TcpClient::run()
{

}

}
