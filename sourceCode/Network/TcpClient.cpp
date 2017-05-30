#include "TcpClient.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "EventIdGenerator.h"
#include "Trace.h"

namespace Network {

TcpClient::TcpClient(const IpSocketEndpoint& localEndpoint, const IpSocketEndpoint& remoteEndpoint)
    :eventId_(EventHandler::EventIdGenerator::generateEventId())
    ,socket_(localEndpoint, remoteEndpoint)
    ,state_(TcpState::Tcp_Closed)
{
}

TcpClient::~TcpClient()
{
}

TcpResult TcpClient::init()
{
    TRACE_ENTER();
    socket_.init();
    return TcpResult::Success;
}

TcpResult TcpClient::connect()
{
    TRACE_DEBUG("localEndpoint:" << socket_.getLocalEndpoint() << ", remoteEndpoint:" << socket_.getRemoteEndpoint());

    int ret = socket_.connect();

    if (SOCKET_ERROR == ret)
    {
        if (SOCKET_EINPROGRESS == socket_.getErrorNo())
        {
            TRACE_NOTICE(socket_.getErrorInfo());
            state_ = TcpState::Tcp_Connecting;
            return TcpResult::Success;
        }
        else
        {
            TRACE_WARNING(socket_.getErrorInfo());
            return TcpResult::Failed;
        }
    }
    else
    {
        return TcpResult::Success;
    }
}

TcpResult TcpClient::send(const Serialize::WriteBuffer& buffer)
{
    TRACE_ENTER();
    if (SOCKET_ERROR == socket_.send(buffer.getBuffer(), buffer.getDataSize(), SOCKET_FLAG_NONE))
    {
        TRACE_NOTICE(socket_.getErrorInfo());
        return TcpResult::Failed;
    }
    else
    {
        return TcpResult::Success;
    }
}

TcpResult TcpClient::receive(Serialize::ReadBuffer& buffer)
{
    TRACE_ENTER();
    if (SOCKET_ERROR == socket_.recv(buffer.getBuffer(), buffer.getBufferSize(), SOCKET_FLAG_NONE))
    {
        TRACE_NOTICE(socket_.getErrorInfo());
        return TcpResult::Failed;
    }
    else
    {
        return TcpResult::Success;
    }
}

TcpResult TcpClient::disconnect()
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

TcpResult TcpClient::cleanup()
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

void TcpClient::run(EventHandler::EventFlag flag)
{
    static_cast<void>(flag);
}

}
