#include "DeviceConnectionReceiverCreator.h"
#include "IoeZpConnectionReceiver.h"

namespace DeviceCommunication {
DeviceConnectionReceiverCreator::DeviceConnectionReceiverCreator()
{

}

Network::ITcpConnectionReceiver* DeviceConnectionReceiverCreator::create(DeviceType type, const Network::IpSocketEndpoint& remoteIpEndpoint, IDeviceClientManager& manager)
{
    switch (type) {
    case DeviceType::IOEZP:
        return new IoeZpConnectionReceiver(remoteIpEndpoint, manager);
        break;
    default:
        return nullptr;
    }
}
}
