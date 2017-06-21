#ifndef _IPCMESSAGE_IPCMESSAGETYPE_H_
#define _IPCMESSAGE_IPCMESSAGETYPE_H_
namespace IpcMessage {

enum IpcMessageType
{
    IpcMessage_None,
    IpcMessage_SystemMonitor
};

enum SystemMonitorType
{
    SystemInfoRequest,  // request the system information
    SystemInfoMessage  // system information message
};

}
#endif // _IPCMESSAGE_IPCMESSAGETYPE_H_
