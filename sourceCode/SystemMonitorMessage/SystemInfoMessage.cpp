#include "SystemInfoMessage.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "Trace.h"
#include "App.h"
#include <stdint.h>

namespace SystemMonitorMessage {

SystemInfoMessage::SystemInfoMessage()
{

}

SystemInfoMessage::SystemInfoMessage(const Environment::CpuUsageInfo& cpuUsageInfo)
    : cpuUsageInfo_(cpuUsageInfo)
{
}

const Environment::CpuUsageInfo& SystemInfoMessage::getCpuUsageInfo() const
{
    return cpuUsageInfo_;
}


SystemInfoMessage::~SystemInfoMessage()
{

}

void SystemInfoMessage::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    TRACE_ENTER();
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::IpcMessageType::IpcMessage_SystemMonitor));
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::SystemInfoMessage));
    cpuUsageInfo_.serialize(writeBuffer);
}

void SystemInfoMessage::unserialize(Serialize::ReadBuffer& readBuffer)
{
    TRACE_ENTER();
    uint8_t temp = 0;
    readBuffer.read<uint8_t>(temp);
    IpcMessage::IpcMessageType type = static_cast<IpcMessage::IpcMessageType>(temp);
    if (type != IpcMessage::IpcMessageType::IpcMessage_SystemMonitor)
    {
        TRACE_ERROR("Receive IPC message with error message type:" << type);
        throw std::runtime_error("Receive IPC message with error message type");
    }
    readBuffer.read<uint8_t>(temp);
    IpcMessage::SystemMonitorType systemMonitorType = static_cast<IpcMessage::SystemMonitorType>(temp);
    if (systemMonitorType != IpcMessage::SystemInfoMessage)
    {
        TRACE_ERROR("Receive system infomation message with error system monitor type:" << IpcMessage::SystemInfoMessage);
        throw std::invalid_argument("Receive system infomation message with error system monitor type:");
    }
    cpuUsageInfo_.unserialize(readBuffer);
}

IpcMessage::SystemMonitorType SystemInfoMessage::getSystemMonitorType() const
{
    return IpcMessage::SystemInfoMessage;
}

std::ostream& SystemInfoMessage::operator<< (std::ostream& os) const
{
    os << "["
       << "ipcMessageType=" << static_cast<int>(IpcMessage::IpcMessage_SystemMonitor)
       << "systemMonitorType=" << static_cast<int>(IpcMessage::SystemInfoMessage)
       << "cpuUsageInfo=" << cpuUsageInfo_
       << "]";
    return os;
}

}