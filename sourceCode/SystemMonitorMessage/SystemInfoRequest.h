#ifndef SYSTEMINFOREQUEST_H
#define SYSTEMINFOREQUEST_H
#include "ISystemMonitorMessage.h"

namespace SystemMonitorMessage {

class SystemInfoRequest : public ISystemMonitorMessage
{
public:
    SystemInfoRequest();
protected:
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);
    virtual SystemMonitorType getSystemMonitorType() const;
};

}

#endif // SYSTEMINFOREQUEST_H
