#include "DeviceMessageGenerator.h"
#include "IoeZpMessage.h"
namespace DeviceMessage {
DeviceMessageGenerator::DeviceMessageGenerator()
{

}

std::unique_ptr<IDeviceMessage> DeviceMessageGenerator::generateIoZpResourceMessage(uint16_t resourceId)
{
    IoeZpMessage* pMsg = new IoeZpMessage();
    std::unique_ptr<IDeviceMessage> message(pMsg);
    IoeZpMessage::IoeZpMessagePayload& payload = pMsg->getPayload();
    payload.resIndex = resourceId & RESOURCE_MASK;
    for (uint16_t index : IoeZpMessage::IoeZpResIdSet)
    {
        if (index & resourceId)
        {
            payload.resources[index] = IoeZpResource(index);
        }
    }

    return std::move(message);
}

}
