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
    virtual DeviceMessageType getMessageType();

    inline uint16_t getHeader() const {return header_;}
    inline void setHeader(uint16_t header) {header_ = header;}
    inline uint8_t getLength() const {return length_;}
    inline void setLength(uint8_t length) {length_ = length;}
    inline uint8_t getLengthInverse() const {return length_Inverse_;}
    inline void setLengthInverse(uint8_t length_Inverse) {length_Inverse_ = length_Inverse;}
    inline uint8_t getCheckSum() const {return checkSum_;}
    inline void setCheckSum(uint8_t checkSum) {checkSum_ = checkSum;}
    inline uint8_t getCmd() const {return cmd_;}
    inline void setCmd(uint8_t checkSum) {cmd_ = checkSum;}
    inline IoeZpMessagePayload& getPayload() {return payload_;}
};
}
#endif // _DEVICEMESSAGE_IOEZPMESSAGE_H_
