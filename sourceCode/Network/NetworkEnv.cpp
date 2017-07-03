#include "NetworkEnv.h"
#include "SocketWrapper.h"
namespace Network {
NetworkEnv::NetworkEnv()
{

}

IpAddresses NetworkEnv::getLocalIpAddress()
{
    IpAddresses addresses;

    if (SOCKET_SUCCESS != IoPlatformWrapper::InitSocket())
    {
        return addresses;
    }

    std::string hostname;
    if (IoPlatformWrapper::GetHostName(hostname))
    {
        return addresses;
    }

    SocketHostent* hostent = IoPlatformWrapper::GetHostByName(hostname);
    if (nullptr == hostent)
    {
        return addresses;
    }

    unsigned int i = 0;
    while (hostent->h_addr_list[i] != nullptr)
    {
        const std::string ipAddr = IoPlatformWrapper::InetNtoa(*((struct in_addr *)hostent->h_addr_list[i]));
        addresses.push_back(IpAddress(ipAddr));
        i++;
    }
    return addresses;
}

}
