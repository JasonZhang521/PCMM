#include "SystemMonitorConnectionTx.h"
#include "ISystemMonitorMessage.h"
#include "ReadBuffer.h"
#include "Trace.h"
#include <stdint.h>

namespace SystemMonitor {
SystemMonitorConnectionTx::SystemMonitorConnectionTx(std::shared_ptr<ISystemMonitorHandler> monitorHandler)
    :monitorHandler_(monitorHandler)
{
}

SystemMonitorConnectionTx::~SystemMonitorConnectionTx()
{

}

void SystemMonitorHandler::onConnect()
{

}

void SystemMonitorHandler::onReceive(Serialize::ReadBuffer& readBuffer)
{
    TRACE_ENTER();
    uint8_t type = 0xFF;
    readBuffer.read(type);
    SystemMonitorMessage::SystemMonitorType systemMonitorType = static_cast<SystemMonitorMessage::SystemMonitorType>(type);
    switch (systemMonitorType)
    {
    case SystemMonitorMessage::SystemMonitorType::MonitorReportResponse:
        break;
    case SystemMonitorMessage::SystemMonitorType::MonitorRequest:
        monitorHandler_->reportSystemInfo();
        break;
    default:
        TRACE_ERROR("Unsupported message! message type = " << systemMonitorType);
        break;
    }
}

void SystemMonitorHandler::onDisconnect()
{

}

}
