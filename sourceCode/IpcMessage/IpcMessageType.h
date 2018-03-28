#ifndef _IPCMESSAGE_IPCMESSAGETYPE_H_
#define _IPCMESSAGE_IPCMESSAGETYPE_H_
#include <string>
namespace IpcMessage {

enum IpcMessageType
{
    IpcMessage_None,
    IpcMessage_IpcCommunication,
    IpcMessage_SystemMonitor,
    IpcMessage_ConfigureMgt,
    IpcMessage_ShellCommand,
    IpcMessage_ChatSession
};
std::string IpcMessageTypeString(IpcMessageType type);

enum SystemMonitorMessageType
{
    ComputerNodeInfoRequestMessage,  // request the system information
    ComputerNodeInfoReportMessage,  // system information message
    ControlNodeBrieflyInfoRequestMessage,
    ControlNodeBrieflyInfoResponseMessage
};
std::string SystemMonitorTypeString(SystemMonitorMessageType type);

enum IpcCommunicationMessageType
{
    IpcHeartbeatReportMessage,
    IpcAuthorizationRequstMessage,
    IpcAuthorizationResponseMessage
};
std::string IpcCommunicationTypeString(IpcCommunicationMessageType type);

enum IpcConfigureMgtMessageType
{
    ManuiConfigureMgtAcquireRequestMessage,
    ManuiConfigureMgtAcquireResponseMessage,
    ManuiConfigureMgtUpdateRequestMessage,
    ManuiConfigureMgtUpdateResponseMessage
};

std::string IpcConfigureMgtTypeToString(IpcConfigureMgtMessageType type);

enum IpcShellCommandMessageType
{
    ShellCommandRequestMessage,
    ShellCommandResponseMessage
};

std::string IpcShellCommandTypeToString(IpcShellCommandMessageType type);

enum IpcChatMessageType
{
    ChatTextMessage,
    ChatFileMessage,
    ChatFileRequestMessage,
    ChatFileFragmentRequestMessage,
    ChatAuthorizationRequest,
    ChatAuthorizationResponse
};

std::string IpcChatMessageTypeToString(IpcChatMessageType type);

}
#endif // _IPCMESSAGE_IPCMESSAGETYPE_H_
