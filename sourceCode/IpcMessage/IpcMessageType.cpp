#include "IpcMessageType.h"
namespace IpcMessage {
std::string IpcMessageTypeString(IpcMessageType type)
{
    switch (type) {
    case IpcMessage_IpcCommunication:
        return std::string("IpcMessage_IpcComunication");
    case IpcMessage_SystemMonitor:
        return std::string("IpcMessage_SystemMonitor");
    case IpcMessage_ClusterMgt:
        return std::string("IpcMessage_ClusterMgt");
    case IpcMessage_ConfigureMgt:
        return std::string("IpcMessage_ConfigureMgt");
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
        return std::string("SystemInfoUnknownMessage");
    }
}

std::string IpcCommunicationTypeString(IpcCommunicationMessageType type)
{
    switch (type) {
    case IpcHeartbeatReportMessage:
        return std::string("IpcHeartbeatReport");
    case IpcAuthorizationRequstMessage:
        return std::string("IpcAuthorizationRequst");
    case IpcAuthorizationResponseMessage:
        return std::string("IpcAuthorizationResponse");
    default:
        return std::string("IpcHeartbeatUnknownMessage");
    }
}

std::string IpcClusterMgtTypeToString(IpcClusterMgtMessageType type)
{
    switch (type) {
    case ClusterMgtBrieflyRequestMessage:
        return std::string("ClusterMgtBrieflyRequest");
    case ClusterMgtBrieflyResponseMessage:
        return std::string("ClusterMgtBrieflyResonse");
    default:
        return std::string("ClusterMgtBrieflyUnknownMessage");
        break;
    }
}

std::string IpcConfigureMgtTypeToString(IpcConfigureMgtMessageType type)
{
    switch (type) {
    case ManuiConfigureMgtAcquireRequestMessage:
        return std::string("ManuiConfigureMgtAcquireRequestMessage");
    case ManuiConfigureMgtAcquireResponseMessage:
        return std::string("ManuiConfigureMgtAcquireResponseMessage");
    case ManuiConfigureMgtUpdateRequestMessage:
        return std::string("ManuiConfigureMgtUpdateRequestMessage");
    case ManuiConfigureMgtUpdateResponseMessage:
        return std::string("ManuiConfigureMgtUpdateResponseMessage");
    default:
        return std::string("ConfigureMgtUnknownMessage");
        break;
    }
}

}
