#include "TcpClient.h"
#include "TcpSocket.h"
#include "ITcpConnectionReceiver.h"
#include "IpSocketEndpoint.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "EventIdGenerator.h"
#include "LoopMain.h"
#include "Trace.h"
#include "App.h"

namespace Network {


TcpClient::ConnectionTimer::ConnectionTimer(ITcpClient* client)
    : TimerHandler::ITimer(3000)
    , client_(client)
    , state_(Connecting)
{
    if (client == nullptr)
    {
        throw std::invalid_argument("nullptr for tcp client!");
    }
}

void TcpClient::ConnectionTimer::onTime()
{
    TRACE_WARNING("Tcp client connect to server timeout, state = " << static_cast<int>(state_) << " client:" << *dynamic_cast<TcpClient*>(client_)->socket_);
    switch (state_) {
    case Connecting:
         client_->disconnect();
         state_ = DisConnecting;
        break;
    case DisConnecting:
        client_->restart();
        client_->connect();
        state_ = Connecting;
        break;
    default:
        break;
    }
    resetTimer();
    Core::LoopMain::instance().registerTimer(this);
}

std::ostream& TcpClient::ConnectionTimer::operator<<(std::ostream& os)
{
    return os;
}

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

TcpClient::TcpClient(std::shared_ptr<TcpSocket> socket)
    :state_(TcpState::Tcp_Closed)
    ,socket_(socket)
{

}

TcpClient::~TcpClient()
{
}

TcpResult TcpClient::init()
{
    TRACE_ENTER();
    socket_->init();
    socket_->bind();
    return TcpResult::Success;
}

TcpResult TcpClient::connect()
{
    TRACE_DEBUG("localEndpoint:" << socket_->getLocalEndpoint() << ", remoteEndpoint:" << socket_->getRemoteEndpoint());

    int ret = socket_->connect();

    if (SOCKET_ERROR == ret)
    {
        int errorNo = socket_->getErrorNo();
        if (SOCKET_EINPROGRESS == errorNo || SOCKET_EWOULDBLOCK == errorNo)
        {
            TRACE_NOTICE(socket_->getErrorInfo() << " socket = " << *socket_);
            state_ = TcpState::Tcp_Connecting;
            if (!connectionTimer_)
            {
                connectionTimer_ = std::shared_ptr<ConnectionTimer>(new ConnectionTimer(this));
                Core::LoopMain::instance().registerTimer(connectionTimer_.get());
                Core::LoopMain::instance().registerIo(Io::IoFdType::IoFdWrite, this);
            }
            return TcpResult::Success;    
        }
        else if (SOCKET_SUCCESS == errorNo)
        {
            TRACE_NOTICE("client connect to server successfully, socket = " << *socket_);
            state_ = TcpState::Tcp_Established;
            tcpConnectionReceiver_->onConnect();
            return TcpResult::Success;
        }
        else
        {
            TRACE_WARNING(socket_->getErrorInfo() << ", socket = " << *socket_);
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

TcpResult TcpClient::restart()
{
    TRACE_ENTER();
    socket_ = std::shared_ptr<TcpSocket>(new TcpSocket(socket_->getRemoteEndpoint(), socket_->getRemoteEndpoint()));
    return TcpResult::Success;
}

void TcpClient::run(EventHandler::EventFlag flag)
{
    TRACE_ENTER();
    if (state_ == TcpState::Tcp_Established)
    {
        if (flag == EventHandler::EventFlag::Event_IoRead)
        {
            receive();
        }
    }
    else if (state_ == TcpState::Tcp_Connecting)
    {
        if (flag == EventHandler::EventFlag::Event_IoWrite)
        {
            TRACE_NOTICE("client connect to server successfully, socket = " << *socket_);
            state_ = TcpState::Tcp_Established;
            Core::LoopMain::instance().deRegisterIo(getIoHandle(), Io::IoFdType::IoFdWrite);
            Core::LoopMain::instance().deRegisterTimer(connectionTimer_->getTimerId());
        }
    }
}

std::ostream& TcpClient::operator<< (std::ostream& os) const
{
    os << "["
       << "Tcpclient: state=" << toString(state_)
       << "socket=" << *socket_
       << "]";

    return os;
}

int TcpClient::getIoHandle()
{
    TRACE_ENTER();
    return socket_->getFd();
}

void TcpClient::setConnectionReceiver(std::shared_ptr<ITcpConnectionReceiver> receiver)
{
    TRACE_ENTER();
    tcpConnectionReceiver_ = receiver;
}


}
