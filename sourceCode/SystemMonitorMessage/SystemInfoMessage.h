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
public:
    SystemInfoMessage();
    SystemInfoMessage(const Environment::CpuUsageInfo& cpuUsageInfo);
    const Environment::CpuUsageInfo& getCpuUsageInfo() const;
    virtual ~SystemInfoMessage();

private:
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);
    virtual IpcMessage::SystemMonitorType getSystemMonitorType() const;
    virtual std::ostream& operator<< (std::ostream& os) const;

private:
    void write(Serialize::WriteBuffer& writeBuffer) const;
    void read(Serialize::ReadBuffer& readBuffer);
    void print(std::ostream& os) const;
public:
    GETCLASSNAME(SystemInfoMessage)
};

}

#endif // _SYSTEMMONITORMESSAGE_SYSTEMINFOMESSAGE_H_
