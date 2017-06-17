#include "SystemInfoRequest.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "Trace.h"

namespace SystemMonitorMessage {

SystemInfoRequest::SystemInfoRequest()
{

}

void SystemInfoRequest::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    TRACE_ENTER();
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::IpcMessageType::IpcMessage_SystemMonitor));
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::MonitorRequest));
}

void SystemInfoRequest::unserialize(Serialize::ReadBuffer& readBuffer)
{
    static_cast<void>(readBuffer);
}

IpcMessage::SystemMonitorType SystemInfoRequest::getSystemMonitorType() const
{
    return IpcMessage::MonitorRequest;
}
}
