#include "TcpClient.h"
#include "TcpSocket.h"
#include "IConnectionTx.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "EventIdGenerator.h"
#include "Trace.h"
#include "App.h"

namespace Network {

TcpClient::TcpClient(const IpSocketEndpoint& localEndpoint,
                     const IpSocketEndpoint& remoteEndpoint,
                     std::shared_ptr<Connection::IConnectionTx> tx)
    :eventId_(EventHandler::EventIdGenerator::generateEventId())
    ,state_(TcpState::Tcp_Closed)
    ,socket_(new TcpSocket(localEndpoint, remoteEndpoint))
    ,connectionTx_(tx)
{
    if (!tx)
    {
        TRACE_ERROR("Initial Tcp Client with null connectionTx, local = " << localEndpoint << ", remote = " << remoteEndpoint);
        App::ExitWithCoredump();
    }
}

TcpClient::~TcpClient()
{
}

TcpResult TcpClient::init()
{
    TRACE_ENTER();
    socket_->init();
    return TcpResult::Success;
}

TcpResult TcpClient::connect()
{
    TRACE_DEBUG("localEndpoint:" << socket_->getLocalEndpoint() << ", remoteEndpoint:" << socket_->getRemoteEndpoint());

    int ret = socket_->connect();

    if (SOCKET_ERROR == ret)
    {
        if (SOCKET_EINPROGRESS == socket_->getErrorNo())
        {
            TRACE_NOTICE(socket_->getErrorInfo());
            state_ = TcpState::Tcp_Connecting;
            connectionTx_->onConnect();
            return TcpResult::Success;    
        }
        else
        {
            TRACE_WARNING(socket_->getErrorInfo());
            return TcpResult::Failed;
        }
    }
    else
    {
        state_ = TcpState::Tcp_Established;
        return TcpResult::Success;
    }
}

TcpResult TcpClient::send(const Serialize::WriteBuffer& buffer)
{
    TRACE_ENTER();
    if (SOCKET_ERROR == socket_->send(buffer.getBuffer(), buffer.getDataSize(), SOCKET_FLAG_NONE))
    {
        TRACE_WARNING(socket_->getErrorInfo());
        return TcpResult::Failed;
    }
    else
    {
        return TcpResult::Success;
    }
}

TcpResult TcpClient::receive()
{
    TRACE_ENTER();
    Serialize::ReadBuffer readBuffer;
    int numOfBytesReceived = socket_->recv(readBuffer.getBuffer(), readBuffer.getBufferSize(), SOCKET_FLAG_NONE);
    if (SOCKET_ERROR == numOfBytesReceived)
    {
        TRACE_WARNING(socket_->getErrorInfo());
        return TcpResult::Failed;
    }
    else
    {
        connectionTx_->onReceive(readBuffer);
        return TcpResult::Success;
    }
}

TcpResult TcpClient::disconnect()
{
    TRACE_ENTER();
    state_ = TcpState::Tcp_Closed;
    if (SOCKET_ERROR == socket_->close())
    {
        TRACE_NOTICE(socket_->getErrorInfo());
        return TcpResult::Failed;
    }
    else
    {
        connectionTx_->onDisconnect();
        return TcpResult::Success;
    }
}

TcpResult TcpClient::cleanup()
{
    TRACE_ENTER();
    if (SOCKET_ERROR == socket_->shutdown(SOCKET_SD_BOTH))
    {
        TRACE_NOTICE(socket_->getErrorInfo());
        return TcpResult::Failed;
    }
    else
    {
        return TcpResult::Success;
    }
}

void TcpClient::run(EventHandler::EventFlag flag)
{
    if (state_ == TcpState::Tcp_Established)
    {
        if (flag == EventHandler::EventFlag::Event_IoRead)
        {
            receive();
        }
    }
}

}
