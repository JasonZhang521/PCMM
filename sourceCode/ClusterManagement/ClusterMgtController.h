#ifndef CLUSTERMGTCONTROLLER_H
#define CLUSTERMGTCONTROLLER_H
#include "IClusterMgtController.h"
#include "ClusterMgtClientType.h"
#include "Component.h"
#include "Macro.h"
#include <map>
#include <memory>

namespace ClusterManagement {

class IClusterMgtClientsManagement;

class ClusterMgtController : public IClusterMgtController
{
    using ClientsManagementMap = std::map<ClientType, std::shared_ptr<IClusterMgtClientsManagement> >;
    ClientsManagementMap clientsManager_;
public:
    ClusterMgtController();
    virtual ~ClusterMgtController();
    virtual void startup();
    virtual void shutdown();
    virtual void addAcceptedIpcClient(const std::string& remoteEndPoint, std::shared_ptr<Ipc::IIpcClient> ipcClient, ClientType type);
    virtual void handleMessage(const IpcMessage::IIpcMessage& msg, ClientType fromClientType);
    virtual void addClientManager(ClientType type, std::shared_ptr<IClusterMgtClientsManagement> clientManager);

public:
    GETCLASSNAME(ClusterMgtController)
};

}

#endif // CLUSTERMGTCONTROLLER_H
