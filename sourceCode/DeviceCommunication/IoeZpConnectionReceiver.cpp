#include "IoeZpConnectionReceiver.h"
#include "IoeZpMessage.h"
#include "DeviceInfo.h"
#include "DeviceClientManager.h"
#include <memory>

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
    DeviceMessage::IoeZpMessage message;
    message.unserialize(readBuffer);
//    clientManager_.handleMessage(message);
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
}

void IoeZpConnectionReceiver::onDisconnect()
{

}
}
