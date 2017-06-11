#include "SystemInfoRequest.h"
namespace SystemMonitorMessage {

SystemInfoRequest::SystemInfoRequest()
{

}

void SystemInfoReportResponse::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    TRACE_ENTER();
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::IpcMessageType::IpcMessage_SystemMonitor));
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(MonitorRequest));
}

void SystemInfoReportResponse::unserialize(Serialize::ReadBuffer& readBuffer)
{

}

SystemMonitorType SystemInfoReportResponse::getSystemMonitorType() const
{
    return MonitorRequest;
}
}
