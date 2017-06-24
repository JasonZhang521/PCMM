#ifndef _CLUSTERMANAGEMENT_ICLUSTERMGTCLIENTSMANAGEMENT_H_
#define _CLUSTERMANAGEMENT_ICLUSTERMGTCLIENTSMANAGEMENT_H_
#include "ClusterMgtClientType.h"
#include <memory>

namespace Ipc {
class IIpcClient;
}

namespace IpcMessage {
class IIpcMessage;
}

namespace ClusterManagement {

class IClusterMgtClientsManagement
{
public:
    IClusterMgtClientsManagement();
    virtual ~IClusterMgtClientsManagement();
    virtual void startup() = 0;
    virtual void shutdown() = 0;
    virtual void addAcceptedIpcClient(const std::string& remoteEndPoint, std::shared_ptr<Ipc::IIpcClient> ipcClient) = 0;
    virtual void handleMessage(const IpcMessage::IIpcMessage& msg) = 0;
};
}

#endif // _CLUSTERMANAGEMENT_ICLUSTERMGTCLIENTSMANAGEMENT_H_
