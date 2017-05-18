#ifndef _NETWORK_IPSOCKETENDPOINT_H_
#define _NETWORK_IPSOCKETENDPOINT_H_
#include "IpPort.h"
#include "IpAddress.h"
#include "ISerializable.h"
#include <string>

namespace Network {

class IpSocketEndpoint : public Serialize::ISerializable
{
    IpAddress ipAddress_;
    IpPort ipPort_;

public:
    IpSocketEndpoint();
    IpSocketEndpoint(const IpSocketEndpoint& ipSocketEndPoint);
    IpSocketEndpoint(const IpAddress& ipAddress, const IpPort& ipPort);
    // IpSocketEndpoint endpoint("10.35.127.80:22");
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

    SocketAddressFamily getSocketAddressFamily() const;

private:
    void parse(const std::string& ipAndPort);
    void parseIpAndPortV4(const std::string& ipAndPort);
};

}

#endif // _NETWORK_IPSOCKETENDPOINT_H_
