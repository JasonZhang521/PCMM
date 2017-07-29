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

    return addresses;
}

std::string NetworkEnv::getHostName()
{
    std::string hostname;
    IoPlatformWrapper::GetHostName(hostname);
    return hostname;
}
void NetworkEnv::getIpAddressFromHostName(IpAddresses& addresses)
{
    std::string hostname;
    if (IoPlatformWrapper::GetHostName(hostname))
    {
        return;
    }

    SocketHostent* hostent = IoPlatformWrapper::GetHostByName(hostname);
    if (nullptr == hostent)
    {
        return;
    }

    unsigned int i = 0;
    while (hostent->h_addr_list[i] != nullptr)
    {
        const std::string ipAddr = IoPlatformWrapper::InetNtoa(*((struct in_addr *)hostent->h_addr_list[i]));
        addresses.push_back(IpAddress(ipAddr));
        i++;
    }
}
void NetworkEnv::getIpAddressFromIf(IpAddresses& addresses)
{
    SocketIfAddress address = nullptr;
    IoPlatformWrapper::GetIfAddrs(&address);
    while (address != nullptr)
    {
		    if (address->ifa_addr->sa_family==AF_INET)
			  {
			        Address$
						  void* tmpAddrPtr=&((struct sockaddr_in *)ifAddrStruct->ifa_addr)->sin_addr;$
							char addressBuffer[INET_ADDRSTRLEN];$
							inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);$
							printf("%s IP Address %s\n", ifAddrStruct->ifa_name, addressBuffer);
        }
    }

}
