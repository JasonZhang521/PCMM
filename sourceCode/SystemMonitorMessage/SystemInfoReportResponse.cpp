#include "SystemInfoReportResponse.h"
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

}

SystemMonitorType SystemInfoReportResponse::getSystemMonitorType() const
{
    return MonitorReportResponse;
}

}
