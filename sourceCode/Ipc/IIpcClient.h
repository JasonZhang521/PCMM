#ifndef IIPCCLIENT_H
#define IIPCCLIENT_H

namespace IpcMessage
{
class IIpcMessage;
}

namespace Ipc {

class IIpcClient
{
public:
    IIpcClient();
    ~IIpcClient();
    virtual void connect() = 0;
    virtual void send(const IpcMessage::IIpcMessage& msg) = 0;
    virtual void disconnect() = 0;
};

}
#endif // IIPCCLIENT_H
