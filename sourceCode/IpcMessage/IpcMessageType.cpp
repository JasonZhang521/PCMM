#include "IpcMessageType.h"
namespace IpcMessage {
std::string IpcMessageTypeString(IpcMessageType type)
{
    switch (type) {
    case IpcMessage_IpcComunication:
        return std::string("IpcMessage_IpcComunication");
    case IpcMessage_SystemMonitor:
        return std::string("IpcMessage_SystemMonitor");
    default:
        return std::string("IpcMessage_Unknown");
    }
}

std::string SystemMonitorTypeString(SystemMonitorMessageType type)
{
    switch (type) {
    case SystemInfoRequest:
        return std::string("SystemInfoRequest");
    case SystemInfoMessage:
        return std::string("SystemInfoMessage");
    default:
        return std::string("SystemInfoUnknown");
    }
}

std::string IpcHeartbeatTypeString(IpcComunicationMessageType type)
{
    switch (type) {
    case IpcHeartbeatReportMessage:
        return std::string("IpcHeartbeatReport");
    default:
        return std::string("IpcHeartbeatUnknown");
    }
}

}
