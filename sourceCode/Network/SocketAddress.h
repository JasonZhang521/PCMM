#ifndef SOCKETADDRESS_H
#define SOCKETADDRESS_H

namespace Network {

enum class IPFamilyType
{
    IPFamilyV4,
    IPFamilyV6,
    IPFamilyInvalid
};

class SocketAddress
{ 
    union
    {
        struct in_addr ipv4;
        struct in6_addr ipv6;
    } addr;
public:
    SocketAddress();
} ;

}
#endif // SOCKETADDRESS_H
