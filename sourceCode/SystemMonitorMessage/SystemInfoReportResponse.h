#ifndef SYSTEMINFOREPORTRESPONSE_H
#define SYSTEMINFOREPORTRESPONSE_H
#include "ISystemMonitorMessage.h"

namespace SystemMonitorMessage {

class SystemInfoReportResponse : public ISystemMonitorMessage
{
public:
    SystemInfoReportResponse();
protected:
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);

    virtual SystemMonitorType getSystemMonitorType() const;
};

}

#endif // SYSTEMINFOREPORTRESPONSE_H
