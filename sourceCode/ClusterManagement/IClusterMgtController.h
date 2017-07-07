#ifndef ICLUSTERMGTCONTROLLER_H
#define ICLUSTERMGTCONTROLLER_H
#include "ClusterMgtClientType.h"
#include <string>
#include <memory>

namespace Ipc {
class IIpcClient;
}

namespace IpcMessage {
class IIpcMessage;
}

namespace ClusterManagement {
class IClusterMgtClientsManagement;

class IClusterMgtController
{
public:
    IClusterMgtController();
    ~IClusterMgtController();
    virtual void startup() = 0;
    virtual void shutdown() = 0;
    virtual void addAcceptedIpcClient(const std::string& remoteEndPoint, std::shared_ptr<Ipc::IIpcClient> ipcClient, ClientType type) = 0;
    virtual void removeAcceptedIpcClient(const std::string& remoteEndPoint, ClientType type) = 0;
    virtual void handleMessage(const IpcMessage::IIpcMessage& msg, ClientType fromClientType) = 0;
    virtual void addClientManager(ClientType type, std::shared_ptr<IClusterMgtClientsManagement> clientManager) = 0;
};
}
#endif // ICLUSTERMGTCONTROLLER_H
