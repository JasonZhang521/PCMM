#ifndef _CLUSTERSMANAGEMENT_CLUSTERCONNECTIONACCEPTOR_H_
#define _CLUSTERSMANAGEMENT_CLUSTERCONNECTIONACCEPTOR_H_
#include "IIpcConnectionAcceptor.h"
#include <memory>

namespace ClustersManagement {

class IClustersManagementHandler;
class ClustersMgtConnectionAcceptor : public Ipc::IIpcConnectionAcceptor
{
    std::shared_ptr<IClustersManagementHandler> clustersManagementHandler_;
public:
    ClustersMgtConnectionAcceptor();
    ~ClustersMgtConnectionAcceptor();
    virtual void onAccept(int fd,
                          const Network::IpSocketEndpoint& localEndPoint,
                          const Network::IpSocketEndpoint& remoteEndPoint);
private:
    void createClusterConnection(int fd,
                                 const Network::IpSocketEndpoint& localEndPoint,
                                 const Network::IpSocketEndpoint& remoteEndPoint);
};

}
#endif // _CLUSTERSMANAGEMENT_CLUSTERCONNECTIONACCEPTOR_H_
