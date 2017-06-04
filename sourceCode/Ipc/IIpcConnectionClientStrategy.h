#ifndef _IPC_IIPCCONNECTIONCLIENTSTRATEGY_H_
#define _IPC_IIPCCONNECTIONCLIENTSTRATEGY_H_

namespace Serialize {
class WriteBuffer;
}

namespace Ipc {

class IIpcConnectionClientStrategy
{
public:
    IIpcConnectionClientStrategy();
    virtual ~IIpcConnectionClientStrategy();
    virtual void connect() = 0;
    virtual void send(Serialize::WriteBuffer& writeBuffer) = 0;
    virtual void disconnect() = 0;
};

}

#endif // _IPC_IIPCCONNECTIONCLIENTSTRATEGY_H_
