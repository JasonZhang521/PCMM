#include "IoeZpConnectionReceiver.h"
#include "IoeZpMessage.h"
#include "DeviceInfo.h"
#include "DeviceClientManager.h"
#include "ReadBuffer.h"
#include "Trace.h"
#include "Component.h"
#include "Macro.h"
#include <memory>

namespace DeviceCommunication {

GETCLASSNAME(IoeZpConnectionReceiver)

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
    TRACE_NOTICE("onConnect:" << remoteIpEndpoint_);
}

void IoeZpConnectionReceiver::onReceive(Serialize::ReadBuffer& readBuffer)
{
    TRACE_DEBUG3(readBuffer);
    DeviceMessage::IoeZpMessage message;
    message.unserialize(readBuffer);
//    clientManager_.handleMessage(message);
    Environment::IoeZpDeviceInfo& ioeZpDeviceInfo = Environment::DeviceInfo::instance().getIoeZpDeviceInfo(remoteIpEndpoint_);
    ioeZpDeviceInfo.setNetId(message.getPayload().netId);
    TRACE_DEBUG3(message);
    for (auto it : message.getPayload().resources)
    {
        DeviceMessage::IoeZpResource& ioeZpResource = it.second;
        switch (ioeZpResource.resourceId) {
        case DeviceMessage::USROPTS_BZ06:
            break;
        case DeviceMessage::DEVOPTS_BZ06:
            {
                DeviceMessage::DevoptsBz06* payloadDevoptsBz06 = reinterpret_cast<DeviceMessage::DevoptsBz06*>(ioeZpResource.resource);
                ioeZpDeviceInfo.setDeviceNumber(payloadDevoptsBz06->devNumber);
                ioeZpDeviceInfo.setModelNum(payloadDevoptsBz06->modeINum);
                ioeZpDeviceInfo.setDate(payloadDevoptsBz06->date);
            }
            break;
        case DeviceMessage::RUNDATA_BZ06:
            {
                DeviceMessage::RunDataBz06* payloadRunDataBz06 = reinterpret_cast<DeviceMessage::RunDataBz06*>(ioeZpResource.resource);
                ioeZpDeviceInfo.setTemperature1(payloadRunDataBz06->temp1);
                ioeZpDeviceInfo.setTemperature2(payloadRunDataBz06->temp2);
                ioeZpDeviceInfo.setBatteryVoltage(payloadRunDataBz06->battVol);
                ioeZpDeviceInfo.setHumitidy(payloadRunDataBz06->hum);
            }
            break;
        case DeviceMessage::OUTCTL_BZ06:
            break;
        default:
            break;
        }
    }

    clientManager_.handleMessage(message);
}

void IoeZpConnectionReceiver::onDisconnect()
{
    TRACE_NOTICE("onDisconnect:" << remoteIpEndpoint_);
    clientManager_.removeClient(remoteIpEndpoint_);
}
}
