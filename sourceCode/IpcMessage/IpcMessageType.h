#ifndef _IPCMESSAGE_IPCMESSAGETYPE_H_
#define _IPCMESSAGE_IPCMESSAGETYPE_H_
#include <string>
namespace IpcMessage {

enum IpcMessageType
{
    IpcMessage_None,
    IpcMessage_IpcCommunication,
    IpcMessage_SystemMonitor
};
std::string IpcMessageTypeString(IpcMessageType type);

enum SystemMonitorMessageType
{
    SystemInfoRequest,  // request the system information
    SystemInfoMessage  // system information message
};
std::string SystemMonitorTypeString(SystemMonitorMessageType type);

enum IpcCommunicationMessageType
{
    IpcHeartbeatReportMessage,
    IpcAuthorizationRequstMessage,
    IpcAuthorizationResponseMessage
};
std::string IpcCommunicationTypeString(IpcCommunicationMessageType type);

}
#endif // _IPCMESSAGE_IPCMESSAGETYPE_H_
