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
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::SystemInfoRequest));
}

void SystemInfoRequest::unserialize(Serialize::ReadBuffer& readBuffer)
{
    static_cast<void>(readBuffer);
}

IpcMessage::SystemMonitorType SystemInfoRequest::getSystemMonitorType() const
{
    return IpcMessage::SystemInfoRequest;
}

std::ostream& SystemInfoRequest::operator<< (std::ostream& os) const
{
    os << "["
       << "ipcMessageType=" << static_cast<int>(IpcMessage::IpcMessage_SystemMonitor)
       << "systemMonitorType=" << static_cast<int>(IpcMessage::SystemInfoRequest)
       << "]";
    return os;
}
}
