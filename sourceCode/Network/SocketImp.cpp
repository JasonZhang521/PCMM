#include "SocketImp.h"
#include "Trace.h"
#include <sstream>
namespace Network {

SocketImp::SocketImp(const SocketAddressFamily& addrFamily,
       const SocketType& type,
       const SocketProtocol& protocol)
    :addrFamily_(addrFamily)
    ,type_(type)
    ,protocol_(protocol)
{
    int ret = InitSocket();
    if (ret != SOCKET_SUCCESS)
    {
        TRACE_ERROR("Can not init the socket, " << getErrorInfo());
    }
    fd_ = CreateSocket(addrFamily, type, protocol);
}

SocketImp::SocketImp(const SocketAddressFamily& addrFamily,
          const SocketType& type,
          const SocketProtocol& protocol,
          const SocketHandle& fd)
    :addrFamily_(addrFamily)
    ,type_(type)
    ,protocol_(protocol)
    ,fd_(fd)
{
}

SocketImp::~SocketImp()
{
}

std::string SocketImp::getErrorInfo()
{
    const int Errno = GetLastSocketErrorNo();
    const std::string ErrorInfo = GetSocketErrorMessageFromErrorCode(Errno);
    std::stringstream ss;
    ss << "errno = " << Errno << ", errorInfo = " << ErrorInfo;
    return ss.str();
}

int SocketImp::getErrorNo()
{
    return GetLastSocketErrorNo();
}

}
