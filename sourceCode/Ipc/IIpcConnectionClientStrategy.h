#ifndef _IPC_IIPCCONNECTIONCLIENTSTRATEGY_H_
#define _IPC_IIPCCONNECTIONCLIENTSTRATEGY_H_

namespace Serialize {
class WriteBuffer;
}

namespace IpcMessage {
class IIpcMessage;
}

namespace Ipc {

class IIpcConnectionClientStrategy
{
public:
    IIpcConnectionClientStrategy();
    virtual ~IIpcConnectionClientStrategy();
    virtual void connect() = 0;
    virtual void send(const IpcMessage::IIpcMessage& msg) = 0;
    virtual void disconnect() = 0;
};

}

#endif // _IPC_IIPCCONNECTIONCLIENTSTRATEGY_H_
