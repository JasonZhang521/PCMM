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

SystemInfoMessage::~SystemInfoMessage()
{

}

void SystemInfoMessage::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    TRACE_ENTER();
}

void SystemInfoMessage::unserialize(Serialize::ReadBuffer& readBuffer)
{

}

SystemMonitorType SystemInfoMessage::getSystemMonitorType() const
{

}

}
