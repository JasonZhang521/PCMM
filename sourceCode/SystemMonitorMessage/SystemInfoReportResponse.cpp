#include "SystemInfoReportResponse.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "Trace.h"
namespace SystemMonitorMessage {

SystemInfoReportResponse::SystemInfoReportResponse()
{
}

void SystemInfoReportResponse::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    TRACE_ENTER();
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::IpcMessageType::IpcMessage_SystemMonitor));
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(MonitorReportResponse));
}

void SystemInfoReportResponse::unserialize(Serialize::ReadBuffer& readBuffer)
{
    static_cast<void>(readBuffer);
}

SystemMonitorType SystemInfoReportResponse::getSystemMonitorType() const
{
    return MonitorReportResponse;
}

}
