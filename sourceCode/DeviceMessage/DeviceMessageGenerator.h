#ifndef DEVICEMESSAGEGENERATOR_H
#define DEVICEMESSAGEGENERATOR_H
#include <memory>
namespace DeviceMessage {
class IDeviceMessage;
class DeviceMessageGenerator
{
public:
    DeviceMessageGenerator();
    std::unique_ptr<IDeviceMessage> generateIoZpResourceMessage(uint16_t resourceId);
};
}

#endif // DEVICEMESSAGEGENERATOR_H
