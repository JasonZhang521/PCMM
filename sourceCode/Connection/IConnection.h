#ifndef _CONNECTION_ICONNECTION_H_
#define _CONNECTION_ICONNECTION_H_

namespace Serialize {
class ReadBuffer;
}

namespace Connection {

class IConnection
{
public:
    IConnection();
    virtual ~IConnection();
    virtual void onReceive(Serialize::ReadBuffer& readBuffer) = 0;

};

}

#endif // _CONNECTION_ICONNECTION_H_
