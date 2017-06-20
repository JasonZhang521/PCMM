#ifndef CLUSTERCONNECTIONACCEPTOR_H
#define CLUSTERCONNECTIONACCEPTOR_H
#include "IIpcConnectionAcceptor.h"
#include <memory>

namespace ClustersManagement {
class IClustersManagementHandler;
class ClusterConnectionAcceptor : public Ipc::IIpcConnectionAcceptor
{
    std::shared_ptr<IClustersManagementHandler> clustersManagementHandler_;
public:
    ClusterConnectionAcceptor();
    ~ClusterConnectionAcceptor();
    virtual void onAccept(int fd,
                          const Network::IpSocketEndpoint& localEndPoint,
                          const Network::IpSocketEndpoint& remoteEndPoint);
private:
    void createClusterConnection(int fd,
                                 const Network::IpSocketEndpoint& localEndPoint,
                                 const Network::IpSocketEndpoint& remoteEndPoint);
};

}
#endif // CLUSTERCONNECTIONACCEPTOR_H
