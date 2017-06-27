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
    IpSocketEndpoint(const SocketAddress& socketAddress);

    IpSocketEndpoint& operator=(const IpSocketEndpoint& ipSocketEndpoint);
    bool operator==(const IpSocketEndpoint& ipSocketEndpoint);
    bool operator!=(const IpSocketEndpoint& ipSocketEndpoint);
    bool operator>(const IpSocketEndpoint& ipSocketEndpoint);
    bool operator<(const IpSocketEndpoint& ipSocketEndpoint);

    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);
    std::string toString() const;

    IPFamilyType getIpFamilyType() const;
    SocketAddressFamily getSocketAddressFamily() const;
    IpAddress getIpAddress() const;
    IpPort getIpPort() const;
    void setIpAddress(const IpAddress& address);
    void setIpPort(const IpPort& port);
    SocketAddressIn getSocketAddressIpv4() const;
    SocketAddressIn6 getSocketAddressIpv6() const;

private:
    void parse(const std::string& ipAndPort);
    void parseIpAndPortV4(const std::string& ipAndPort);

public:
    static const IpSocketEndpoint Null;
};

}

std::ostream& operator<<(std::ostream& os, const Network::IpSocketEndpoint& ipSocketEndpoint);

#endif // _NETWORK_IPSOCKETENDPOINT_H_
