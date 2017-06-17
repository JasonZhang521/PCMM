#ifndef SYSTEMINFOREQUEST_H
#define SYSTEMINFOREQUEST_H
#include "ISystemMonitorMessage.h"
#include "Component.h"
#include "Macro.h"

namespace SystemMonitorMessage {

class SystemInfoRequest : public ISystemMonitorMessage
{
public:
    SystemInfoRequest();
protected:
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);
    virtual IpcMessage::SystemMonitorType getSystemMonitorType() const;

public:
    GETCLASSNAME(SystemInfoRequest)
};

}

#endif // SYSTEMINFOREQUEST_H
