#ifndef _DEVICEMESSAGE_IOEZPMESSAGE_H_
#define _DEVICEMESSAGE_IOEZPMESSAGE_H_
#include "IDeviceMessage.h"
#include "IoeZpResource.h"
#include <string>
#include <vector>
#include <map>
#include "stdint.h"

namespace DeviceMessage {

const uint16_t FixHeader = 0xA5A5;
const uint16_t CMD_GET_RES = 0x1101;
const uint16_t CMD_SET_RES = 0x1102;
const uint16_t CMD_UP_RES = 0x1103;

class IoeZpMessage : public IDeviceMessage
{
    uint16_t header_;
    uint8_t length_;
    uint8_t length_Inverse_;
    uint16_t checkSum_;
    uint16_t cmd_;
    struct IoeZpMessagePayload
    {
        uint64_t reserved;
        uint32_t netId;
        uint16_t extnum;
        uint16_t mode;
        uint16_t resIndex;
        uint16_t resOffset;
        uint8_t resLength;
        uint8_t* resData;
        std::map<uint16_t, IoeZpResource> resources;
        std::string modeName() const;
        IoeZpMessagePayload();
        ~IoeZpMessagePayload();
        void serialize(Serialize::WriteBuffer& writeBuffer) const;
        void unserialize(Serialize::ReadBuffer& readBuffer);
        static void initIoeZpResIdSet();
    };

    IoeZpMessagePayload payload_;
    static std::vector<uint16_t> IoeZpResIdSet;
public:
    IoeZpMessage();
    virtual ~IoeZpMessage();
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);
};
}
#endif // _DEVICEMESSAGE_IOEZPMESSAGE_H_
