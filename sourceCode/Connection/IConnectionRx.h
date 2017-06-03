#ifndef ICONNECTIONRX_H
#define ICONNECTIONRX_H

namespace Serialize {
class WriteBuffer;
}

namespace Connection {

class IConnectionRx
{
public:
    IConnectionRx();
    virtual ~IConnectionRx();

    virtual void connect() = 0;
    virtual void send(Serialize::WriteBuffer& writeBuffer) = 0;
    virtual void disconnect() = 0;
};

}
#endif // ICONNECTIONRX_H
