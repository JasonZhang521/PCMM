#ifndef _SYSTEMMONITORMESSAGE_CLUSTERMGTBRIEFLYRESPONSE_H_
#define _SYSTEMMONITORMESSAGE_CLUSTERMGTBRIEFLYRESPONSE_H_
#include "ISystemMonitorMessage.h"
#include "SystemInfoBriefly.h"
#include "IoeZpDeviceInfo.h"

namespace SystemMonitorMessage {

class ControlNodeBrieflyInfoResponse : public ISystemMonitorMessage
{
    Environment::SystemInfoBriefly systemInfoBriefly_;
    Environment::IoeZpDeviceInfos ioeZpDeviceInfos_;
public:
    ControlNodeBrieflyInfoResponse();
    virtual ~ControlNodeBrieflyInfoResponse();
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);

    virtual IpcMessage::SystemMonitorMessageType getSystemMonitorType() const;
    virtual std::ostream& operator<< (std::ostream& os) const;

    void setSystemInfoBriefly(const Environment::SystemInfoBriefly& info);
    const Environment::SystemInfoBriefly& getSystemInfoBriefly() const;
    void setIoeZpDeviceInfos(const Environment::IoeZpDeviceInfos& infos);
    const Environment::IoeZpDeviceInfos& getIoeZpDeviceInfos() const;
};

}

inline std::ostream& operator<< (std::ostream& os, const SystemMonitorMessage::ControlNodeBrieflyInfoResponse& response)
{
    return response.operator <<(os);
}

#endif // _SYSTEMMONITORMESSAGE_CLUSTERMGTBRIEFLYRESPONSE_H_
