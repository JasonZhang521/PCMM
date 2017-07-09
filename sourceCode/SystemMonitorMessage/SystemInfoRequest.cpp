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
    IpcMessage::IIpcMessage::write(writeBuffer);
}

void SystemInfoRequest::unserialize(Serialize::ReadBuffer& readBuffer)
{
    uint8_t temp = 0;
    readBuffer.read(temp);
    readBuffer.read(temp);
    IpcMessage::IIpcMessage::read(readBuffer);
}

IpcMessage::SystemMonitorMessageType SystemInfoRequest::getSystemMonitorType() const
{
    return IpcMessage::SystemInfoRequest;
}

std::ostream& SystemInfoRequest::operator<< (std::ostream& os) const
{
    os << "[";
    IpcMessage::IIpcMessage::print(os);
    os << ", ipcMessageType=" << IpcMessage::IpcMessageTypeString(IpcMessage::IpcMessage_SystemMonitor)
       << ", systemMonitorType=" << IpcMessage::SystemMonitorTypeString(IpcMessage::SystemInfoRequest)
       << "]";
    return os;
}
}
