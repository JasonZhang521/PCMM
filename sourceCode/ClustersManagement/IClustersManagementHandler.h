#ifndef ICLUSTERSMANAGEMENTHANDLER_H
#define ICLUSTERSMANAGEMENTHANDLER_H
#include <memory>

namespace Ipc {
class IpcClient;
}

namespace IpcMessage {
class IIpcMessage;
}

namespace ClustersManagement {
class IClustersManagementHandler
{
public:
    IClustersManagementHandler();
    virtual ~IClustersManagementHandler();
    virtual void addAcceptedIpcClient(int fd, std::shared_ptr<Ipc::IpcClient> ipcClient) = 0;
    virtual void forwardIpcMessage(std::unique_ptr<IpcMessage::IIpcMessage> msg) = 0;
};
}

#endif // ICLUSTERSMANAGEMENTHANDLER_H
