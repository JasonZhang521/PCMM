#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include "ITcpClient.h"
#include "IIoEvent.h"
#include "ITimer.h"
#include "TcpState.h"
#include "Component.h"
#include "Macro.h"
#include <memory>

namespace Serialize {
class WriteBuffer;
}

namespace Network {

class TcpSocket;

class TcpClient : public ITcpClient, public Io::IIoEvent
{
    struct ConnectionTimer : public TimerHandler::ITimer
    {
        enum ConnectState
        {
            Connecting,
            DisConnecting
        };

        ConnectionTimer(ITcpClient* client);
        virtual void onTime();
        virtual std::ostream& operator<<(std::ostream& os);
    private:
        ITcpClient* client_;
        ConnectState state_;
        unsigned int connectTryCount_;
    public:
        GETCLASSNAME(ConnectionTimer)
    };

    TcpState state_;
    std::shared_ptr<TcpSocket> socket_;
    std::shared_ptr<ITcpConnectionReceiver> tcpConnectionReceiver_;
    std::shared_ptr<TimerHandler::ITimer> connectionTimer_;
public:
    TcpClient(const IpSocketEndpoint& localEndpoint,
              const IpSocketEndpoint& remoteEndpoint,
              std::shared_ptr<ITcpConnectionReceiver> receiver);
    TcpClient(const IpSocketEndpoint& localEndpoint, const IpSocketEndpoint& remoteEndpoint);
    TcpClient(std::shared_ptr<TcpSocket> socket);
    virtual ~TcpClient();
private:
    virtual TcpResult init();
    virtual TcpResult bind();
    virtual TcpResult connect();
    virtual TcpResult send(const Serialize::WriteBuffer&);
    virtual TcpResult receive();
    virtual TcpResult disconnect();
    virtual TcpResult cleanup();
    virtual TcpResult restart();
    virtual void setConnectionReceiver(std::shared_ptr<ITcpConnectionReceiver> receiver);

    virtual void run(EventHandler::EventFlag flag = EventHandler::EventFlag::Event_NoFlag);
    virtual std::ostream& operator<< (std::ostream& os) const;
    virtual int getIoHandle();

public:
     GETCLASSNAME(TcpClient)
};

}

#endif // TCPCLIENT_H
