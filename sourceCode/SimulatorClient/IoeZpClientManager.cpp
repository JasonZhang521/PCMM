#include "IoeZpClientManager.h"

namespace SimulatorClient {
IoeZpClientManager::IoeZpClientManager()
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

}

void IoeZpClientManager::shutdown()
{

}

}
