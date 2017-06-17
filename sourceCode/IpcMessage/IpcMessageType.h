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
    MonitorRequest,  // request the system information
    MonitorMessage  // system information message
};

}
#endif // _IPCMESSAGE_IPCMESSAGETYPE_H_
