#include "DeviceMessageType.h"

namespace DeviceMessage {
std::string DeviceTypeString(DeviceMessageType type)
{
    switch (type) {
    case DeviceMessageType::IoeZpType:
        return std::string("IoeZpType");
        break;
    default:
        return std::string("None");
        break;
    }
}

}
