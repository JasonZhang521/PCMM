#include "IpAddress.h"
#include <string.h>
namespace Network {

IpAddress::IpAddress()
:ipType_(IPFamilyInvalid)
{
    memset(&addr_.ipv4, 0, sizeof(SocketInetAddress));
    memset(&addr_.ipv6, 0, sizeof(SocketInet6Address));
}

IpAddress::IpAddress(uint32_t address)
:ipType_(IPFamilyV4)
{
    memset(&addr_.ipv6, 0, sizeof(SocketInet6Address));
    uint32_t addr = htonl(address);
    memcpy(&addr_.ipv4, &addr, sizeof(SocketInetAddress));
}

IpAddress::IpAddress(const uint8_t* ipv6address)
:ipType_(IPFamilyV6)
{
    memset(&addr_.ipv4, 0, sizeof(SocketInetAddress));
    memcpy(&addr_.ipv6, ipv6address, sizeof(SocketInet6Address));
}

IpAddress::IpAddress(const SocketInetAddress& address)
:ipType_(IPFamilyV4)
{
    memset(&addr_.ipv6, 0, sizeof(SocketInet6Address));
    memcpy(&addr_.ipv4, &address, sizeof(SocketInetAddress));
}

IpAddress::IpAddress(const SocketInet6Address& ipv6address)
:ipType_(IPFamilyV6)
{
    memset(&addr_.ipv4, 0, sizeof(SocketInetAddress));
    memcpy(&addr_.ipv6, &ipv6address, sizeof(SocketInet6Address));
}

IpAddress::IpAddress(const std::string& address)
{
    memset(&addr_.ipv4, 0, sizeof(SocketInetAddress));
    memset(&addr_.ipv6, 0, sizeof(SocketInet6Address));

    if (InetPton(SOCKET_AF_INET, address.c_str(), &addr_.ipv4))
    {
        ipType_ = IPFamilyV4;
    }
    else if(InetPton(SOCKET_AF_INET, address.c_str(), &addr_.ipv6))
    {
        ipType_ = IPFamilyV6;
    }
    else
    {
        ipType_ = IPFamilyInvalid;
    }
}


const SocketInetAddress& IpAddress::getAddressIpv4() const
{
    return addr_.ipv4;
}

const SocketInet6Address& IpAddress::getAddressIpv6() const
{
    return addr_.ipv6;
}

IPFamilyType IpAddress::getIPFamilyType() const
{
    return ipType_;
}

bool IpAddress::operator==(const IpAddress& other) const
{
    if (ipType_ == IPFamilyV4 && other.ipType_ == IPFamilyV4)
    {
        return (memcmp(&addr_.ipv4, &other.addr_.ipv4, sizeof(SocketInetAddress)) == 0);
    }

    if (ipType_ == IPFamilyV6 && other.ipType_ == IPFamilyV6)
    {
        return (memcmp(&addr_.ipv6, &other.addr_.ipv6, sizeof(SocketInet6Address)) == 0);
    }

    if (ipType_ == IPFamilyInvalid && ipType_ == IPFamilyInvalid)
    {
        return true;
    }

    return false;
}

bool IpAddress::operator!=(const IpAddress& other) const
{
    return !(*this != other);
}

void IpAddress::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    static_cast<void>(writeBuffer);
}

void IpAddress::unserialize(Serialize::ReadBuffer& readBuffer)
{
    static_cast<void>(readBuffer);
}

}
