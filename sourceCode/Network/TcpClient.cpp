#include "TcpClient.h"
#include "TcpSocket.h"
#include "ITcpConnectionReceiver.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "EventIdGenerator.h"
#include "Trace.h"
#include "App.h"

namespace Network {

TcpClient::TcpClient(const IpSocketEndpoint& localEndpoint,
                     const IpSocketEndpoint& remoteEndpoint,
                     std::shared_ptr<ITcpConnectionReceiver> receiver)
    :state_(TcpState::Tcp_Closed)
    ,socket_(new TcpSocket(localEndpoint, remoteEndpoint))
    ,tcpConnectionReceiver_(receiver)
{
    if (!receiver)
    {
        TRACE_ERROR("Initial Tcp Client with null connection connection receiver, local = " << localEndpoint << ", remote = " << remoteEndpoint);
        throw std::invalid_argument("Initial Tcp Client with null connection connection receiver");
    }
}

TcpClient::TcpClient(const IpSocketEndpoint& localEndpoint, const IpSocketEndpoint& remoteEndpoint)
    :state_(TcpState::Tcp_Closed)
    ,socket_(new TcpSocket(localEndpoint, remoteEndpoint))
{

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
            tcpConnectionReceiver_->onConnect();
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
    if (SOCKET_ERROR == socket_->send(reinterpret_cast<SocketDataBuffer>(buffer.getBuffer()), buffer.getDataSize(), SOCKET_FLAG_NONE))
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
    int numOfBytesReceived = socket_->recv(reinterpret_cast<SocketDataBuffer>(readBuffer.getBuffer()), readBuffer.getBufferSize(), SOCKET_FLAG_NONE);
    if (SOCKET_ERROR == numOfBytesReceived)
    {
        TRACE_WARNING(socket_->getErrorInfo());
        return TcpResult::Failed;
    }
    else
    {
        readBuffer.setDataSize(numOfBytesReceived);
        tcpConnectionReceiver_->onReceive(readBuffer);
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
        tcpConnectionReceiver_->onDisconnect();
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

std::ostream& TcpClient::operator<< (std::ostream& os) const
{
    return os;
}

int TcpClient::getIoHandle()
{
    return socket_->getFd();
}

void TcpClient::setConnectionReceiver(std::shared_ptr<ITcpConnectionReceiver> receiver)
{
    tcpConnectionReceiver_ = receiver;
}

}
