#include "IoeZpClientManager.h"
#include "IDeviceClientHandler.h"

namespace SimulatorClient {
IoeZpClientManager::IoeZpClientManager(IDeviceClientHandler& handler)
    :handler_(handler)
{

}

IoeZpClientManager::~IoeZpClientManager()
{

}

void IoeZpClientManager::addClient(const Network::IpSocketEndpoint& localEndPoint, std::unique_ptr<DeviceCommunication::IDeviceClient> client)
{

}

void IoeZpClientManager::removeClient(const Network::IpSocketEndpoint& localEndPoint)
{

}

void IoeZpClientManager::handleMessage(DeviceMessage::IDeviceMessage& message)
{

}

void IoeZpClientManager::setDeviceServer(std::unique_ptr<DeviceCommunication::IDeviceServer> server)
{

}

void IoeZpClientManager::startup()
{
    handler_.startup();
}

void IoeZpClientManager::shutdown()
{
    handler_.shutdown();
}

}
