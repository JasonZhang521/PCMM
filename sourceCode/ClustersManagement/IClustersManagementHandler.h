#ifndef ICLUSTERSMANAGEMENTHANDLER_H
#define ICLUSTERSMANAGEMENTHANDLER_H
#include <memory>

namespace Ipc {
class IpcClient;
}

namespace ClustersManagement {
class IClustersManagementHandler
{
public:
    IClustersManagementHandler();
    virtual ~IClustersManagementHandler();
    virtual void addAcceptedIpcClient(int fd, std::shared_ptr<Ipc::IpcClient> ipcClient) = 0;
};
}

#endif // ICLUSTERSMANAGEMENTHANDLER_H
