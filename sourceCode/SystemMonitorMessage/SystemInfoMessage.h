#ifndef _SYSTEMMONITORMESSAGE_SYSTEMINFOMESSAGE_H_
#define _SYSTEMMONITORMESSAGE_SYSTEMINFOMESSAGE_H_
#include "ISystemMonitorMessage.h"
#include "CpuUsageInfo.h"
#include "Component.h"
#include "Macro.h"

namespace SystemMonitorMessage {

class SystemInfoMessage : public ISystemMonitorMessage
{
    Environment::CpuUsageInfo cpuUsageInfo_;
    SystemMonitorType systemMonitorType_;
public:
    SystemInfoMessage();
    SystemInfoMessage(const Environment::CpuUsageInfo& cpuUsageInfo, SystemMonitorType monitorType);

private:
    ~SystemInfoMessage();
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);
    virtual SystemMonitorType getSystemMonitorType() const;

public:
    GETCLASSNAME(SystemInfoMessage)
};

}

#endif // _SYSTEMMONITORMESSAGE_SYSTEMINFOMESSAGE_H_
