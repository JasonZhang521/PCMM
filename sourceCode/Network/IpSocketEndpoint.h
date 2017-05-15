#ifndef IPSOCKETENDPOINT_H
#define IPSOCKETENDPOINT_H
#include "IpPort.h"
#include "IpAddress.h"
#include "ISerializable.h"

namespace Network {

class IpSocketEndpoint : public Serialize::ISerializable
{
    IpAddress IpAddress_;
    IpPort ipPort_;

public:
    IpSocketEndpoint();
    IpSocketEndpoint(const IpSocketEndpoint& ipSocketEndPoint);
    IpSocketEndpoint(const IpAddress& ipAddress, const IpPort& ipPort);
    IpSocketEndpoint(const std::string& ipAndPort);
    IpSocketEndpoint& operator=(const IpSocketEndpoint& ipSocketEndpoint);
    bool operator==(const IpSocketEndpoint& ipSocketEndpoint);
    bool operator!=(const IpSocketEndpoint& ipSocketEndpoint);
    bool operator>(const IpSocketEndpoint& ipSocketEndpoint);
    bool operator<(const IpSocketEndpoint& ipSocketEndpoint);

    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);
    std::string toString() const;
    std::ostream& operator<<(std::ostream& os) const;

};

}

#endif // IPSOCKETENDPOINT_H
