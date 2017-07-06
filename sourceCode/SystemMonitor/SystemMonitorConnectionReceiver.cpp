#include "SystemMonitorConnectionReceiver.h"
#include "ISystemMonitorMessage.h"
#include "ReadBuffer.h"
#include "Trace.h"
#include <stdint.h>

namespace SystemMonitor {
SystemMonitorConnectionReceiver::SystemMonitorConnectionReceiver(std::shared_ptr<ISystemMonitorHandler> monitorHandler)
    :monitorHandler_(monitorHandler)
{
}

SystemMonitorConnectionReceiver::~SystemMonitorConnectionReceiver()
{

}

void SystemMonitorConnectionReceiver::onConnect()
{
    TRACE_ENTER();
    monitorHandler_->onStartup();
}

void SystemMonitorConnectionReceiver::onReceive(std::unique_ptr<IpcMessage::IIpcMessage> msg)
{
    TRACE_ENTER();
    if (!monitorHandler_)
    {
       TRACE_ERROR("Monitor Handler is not set!");
       throw std::runtime_error("Monitor Handler is not set!");
    }
    if (!msg)
    {
        TRACE_WARNING("Invalid message!");
        return;
    }
    SystemMonitorMessage::ISystemMonitorMessage* message = dynamic_cast<SystemMonitorMessage::ISystemMonitorMessage*>(msg.get());
    if (message != nullptr)
    {
        IpcMessage::SystemMonitorType systemMonitorType = message->getSystemMonitorType();
        switch (systemMonitorType)
        {
        case IpcMessage::SystemMonitorType::SystemInfoRequest:
            monitorHandler_->reportSystemInfo();
            break;
        default:
            TRACE_ERROR("Unsupported message! monitor type = " << systemMonitorType);
            break;
        }
    }
    else
    {
        TRACE_ERROR("Unsupported message! message type = " << msg->getMessageType());
    }
}

void SystemMonitorConnectionReceiver::onDisconnect()
{
    TRACE_ENTER();
    monitorHandler_->onShutdown();
}

}
