#ifndef SYSTEMINFOREPORTRESPONSE_H
#define SYSTEMINFOREPORTRESPONSE_H
#include "ISystemMonitorMessage.h"
#include "Component.h"
#include "Macro.h"

namespace SystemMonitorMessage {

class SystemInfoReportResponse : public ISystemMonitorMessage
{
public:
    SystemInfoReportResponse();
protected:
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);

    virtual SystemMonitorType getSystemMonitorType() const;

public:
    GETCLASSNAME(SystemMonitorMessage)
};

}

#endif // SYSTEMINFOREPORTRESPONSE_H
