#include "IoeZpConnectionReceiver.h"
namespace DeviceCommunication {
IoeZpConnectionReceiver::IoeZpConnectionReceiver(const Network::IpSocketEndpoint& remoteIpEndpoint, IDeviceClientManager& clientManager)
    : remoteIpEndpoint_(remoteIpEndpoint)
    , clientManager_(clientManager)
{

}

IoeZpConnectionReceiver::~IoeZpConnectionReceiver()
{

}

void IoeZpConnectionReceiver::onConnect()
{

}

void IoeZpConnectionReceiver::onReceive(Serialize::ReadBuffer& readBuffer)
{

}

void IoeZpConnectionReceiver::onDisconnect()
{

}
}
