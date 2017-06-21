#ifndef _CLUSTERSMANAGEMENT_CLUSTERSMANAGEMENTHANDLER_H_
#define _CLUSTERSMANAGEMENT_CLUSTERSMANAGEMENTHANDLER_H_
#include "IClustersManagementHandler.h"

namespace ClustersManagement {

class ClustersManagementHandler
{
public:
    ClustersManagementHandler();
    virtual ~ClustersManagementHandler();
    virtual void addAcceptedIpcClient(int fd, std::shared_ptr<Ipc::IpcClient> ipcClient);
    virtual void forwardIpcMessage(std::unique_ptr<IpcMessage::IIpcMessage> msg);
};

}

#endif // _CLUSTERSMANAGEMENT_CLUSTERSMANAGEMENTHANDLER_H_
