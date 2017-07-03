#ifndef NETWORKENV_H
#define NETWORKENV_H
#include <vector>
#include <IpAddress.h>

namespace Network {

using IpAddresses = std::vector<IpAddress>;
class NetworkEnv
{
public:
    NetworkEnv();
    static IpAddresses getLocalIpAddress();
};
}

#endif // NETWORKENV_H
