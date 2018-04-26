#include "DeviceClientManager.h"
#include "IpSocketEndpoint.h"
#include "IDeviceClient.h"

namespace DeviceCommunication {
DeviceClientManager::DeviceClientManager()
{

}

DeviceClientManager::~DeviceClientManager()
{

}

void DeviceClientManager::addClient(const Network::IpSocketEndpoint& localEndPoint, std::unique_ptr<IDeviceClient> client)
{
    auto it = clients_.find(localEndPoint);
    if (it != clients_.end())
    {
        clients_[localEndPoint] = std::move(client);
    }
    else
    {
        clients_[localEndPoint] = std::move(client);
    }
}

void DeviceClientManager::removeClient(const Network::IpSocketEndpoint& localEndPoint)
{
    clients_.erase(localEndPoint);
}

void DeviceClientManager::handleMessage(DeviceMessage::IDeviceMessage& message)
{

}

}
