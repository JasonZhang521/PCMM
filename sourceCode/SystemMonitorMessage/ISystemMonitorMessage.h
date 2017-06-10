#ifndef _SYSTEMMONITORMESSAGE_ISYSTEMMONITORMESSAGE_H_
#define _SYSTEMMONITORMESSAGE_ISYSTEMMONITORMESSAGE_H_
#include "IIpcMessage.h"
namespace SystemMonitorMessage {

enum SystemMonitorType
{
    MonitorRequest,
    MonitorReport,
    MonitorResponse
};

class ISystemMonitorMessage : public IpcMessage::IIpcMessage
{
public:
    ISystemMonitorMessage();
    virtual ~ISystemMonitorMessage();
    virtual IpcMessage::IpcMessageType getMessageType() const;
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const = 0;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer) = 0;

    virtual SystemMonitorType getSystemMonitorType() const = 0;
};

}
#endif // _SYSTEMMONITORMESSAGE_ISYSTEMMONITORMESSAGE_H_
