#include "DeviceClientManager.h"
#include "IpSocketEndpoint.h"
#include "IDeviceClient.h"
#include "IDeviceServer.h"

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
    static_cast<void>(message);
    //    clientManager_.handleMessage(message);
    /*
    Environment::DeviceInfo::instance().getIoeZpDeviceInfo().setNetId(message.getPayload().netId);

    for (auto it : message.getPayload().resources)
    {
        DeviceMessage::IoeZpResource& ioeZpResource = it.second;
        switch (ioeZpResource.resourceId) {
        case DeviceMessage::USROPTS_BZ06:
            break;
        case DeviceMessage::DEVOPTS_BZ06:
            {
                DeviceMessage::DevoptsBz06* payloadDevoptsBz06 = reinterpret_cast<DeviceMessage::DevoptsBz06*>(ioeZpResource.resource);
                Environment::DeviceInfo::instance().getIoeZpDeviceInfo().setDeviceNumber(payloadDevoptsBz06->devNumber);
                Environment::DeviceInfo::instance().getIoeZpDeviceInfo().setModelNum(payloadDevoptsBz06->modeINum);
                Environment::DeviceInfo::instance().getIoeZpDeviceInfo().setDate(payloadDevoptsBz06->date);
            }
            break;
        case DeviceMessage::RUNDATA_BZ06:
            {
                DeviceMessage::RunDataBz06* payloadRunDataBz06 = reinterpret_cast<DeviceMessage::RunDataBz06*>(ioeZpResource.resource);
                Environment::DeviceInfo::instance().getIoeZpDeviceInfo().setTemperature1(payloadRunDataBz06->temp1);
                Environment::DeviceInfo::instance().getIoeZpDeviceInfo().setTemperature2(payloadRunDataBz06->temp2);
                Environment::DeviceInfo::instance().getIoeZpDeviceInfo().setBatteryVoltage(payloadRunDataBz06->battVol);
                Environment::DeviceInfo::instance().getIoeZpDeviceInfo().setHumitidy(payloadRunDataBz06->hum);
            }
            break;
        case DeviceMessage::OUTCTL_BZ06:
            break;
        default:
            break;
        }
    }
    */
}

void DeviceClientManager::setDeviceServer(std::unique_ptr<IDeviceServer> server)
{
    deviceServer_ = std::move(server);
}

void DeviceClientManager::startup()
{
    deviceServer_->startup();
}

void DeviceClientManager::shutdown()
{
    deviceServer_->shutdown();
}

}
