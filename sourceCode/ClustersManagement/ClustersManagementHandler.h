#ifndef _CLUSTERSMANAGEMENT_CLUSTERSMANAGEMENTHANDLER_H_
#define _CLUSTERSMANAGEMENT_CLUSTERSMANAGEMENTHANDLER_H_
#include "IClustersManagementHandler.h"

namespace ClustersManagement {

class ClustersManagementHandler
{
public:
    ClustersManagementHandler();
    ~ClustersManagementHandler();
    virtual void addAcceptedIpcClient(int fd, std::shared_ptr<Ipc::IpcClient> ipcClient);
};

}

#endif // _CLUSTERSMANAGEMENT_CLUSTERSMANAGEMENTHANDLER_H_
