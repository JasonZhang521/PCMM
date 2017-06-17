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

IpcMessage::IIpcMessage* SystemMonitorMessageFactory::createMessage(IpcMessage::IpcMessageIntType type)
{
    if (static_cast<IpcMessage::SystemMonitorType>(type) == IpcMessage::MonitorRequest)
    {
        return new SystemInfoRequest();
    }
    else if (static_cast<IpcMessage::SystemMonitorType>(type) == IpcMessage::MonitorMessage)
    {
        return new SystemInfoMessage();
    }
    else
    {
        TRACE_ERROR("Only support message type: MonitorRequest and MonitorMessage!");
        throw std::invalid_argument("Only support message type: MonitorRequest and MonitorMessage!");
    }
}
}
