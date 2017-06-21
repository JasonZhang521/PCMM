#include "SystemMonitorMessageFactory.h"
#include "SystemInfoMessage.h"
#include "SystemInfoRequest.h"
#include "Trace.h"

namespace SystemMonitorMessage {
SystemMonitorMessageFactory::SystemMonitorMessageFactory()
{

}

SystemMonitorMessageFactory::~SystemMonitorMessageFactory()
{

}

IpcMessage::IIpcMessage* SystemMonitorMessageFactory::createMessage(IpcMessage::IpcMessageIntType type) const
{
    if (static_cast<IpcMessage::SystemMonitorType>(type) == IpcMessage::SystemInfoRequest)
    {
        return new SystemInfoRequest();
    }
    else if (static_cast<IpcMessage::SystemMonitorType>(type) == IpcMessage::SystemInfoMessage)
    {
        return new SystemInfoMessage();
    }
    else
    {
        TRACE_ERROR("Only support message type: MonitorRequest and MonitorMessage!");
        return nullptr;
    }
}
}
