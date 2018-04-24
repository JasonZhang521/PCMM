#ifndef _DEVICEMESSAGE_DEVICEMESSAGETYPE_H_
#define _DEVICEMESSAGE_DEVICEMESSAGETYPE_H_
#include <string>
namespace DeviceMessage {
enum class DeviceMessageType
{
    IoeZpType
};

std::string DeviceTypeString(DeviceMessageType type);
}
#endif // _DEVICEMESSAGE_DEVICEMESSAGETYPE_H_
