#include "SocketWrapper.h"
#ifdef WIN32

#else

#endif

namespace Network {
#ifdef WIN32
int InitSocket()
{
    WORD wVersionRequested = MAKEWORD( 2, 2 );
    WSADATA wsaData;
    int err = WSAStartup( wVersionRequested, &wsaData );
    if ( err != 0 ) {
        /* Tell the user that we could not find a usable */
        /* WinSock DLL.                                  */
        return err;
    }

    /* Confirm that the WinSock DLL supports 2.2.*/
    /* Note that if the DLL supports versions greater    */
    /* than 2.2 in addition to 2.2, it will still return */
    /* 2.2 in wVersion since that is the version we      */
    /* requested.                                        */

    if ( LOBYTE( wsaData.wVersion ) != 2 ||
            HIBYTE( wsaData.wVersion ) != 2 ) {
        /* Tell the user that we could not find a usable */
        /* WinSock DLL.                                  */
        WSACleanup( );
        return UNSUPPORTED_SOCKET_VERION;
    }

    return SOCKET_SUCCESS;
}

std::string GetLastSocketErrorMessage()
{
    int nErrno = WSAGetLastError();
    return GetSocketErrorMessageFromErrorCode(nErrno);
}

std::string GetSocketErrorMessageFromErrorCode(int errorCode)
{
    LPTSTR lpMsgBuf;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        errorCode,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf,
        0,
        NULL
        );
    std::string errorMsg = std::string(reinterpret_cast<char*>(lpMsgBuf));
    LocalFree(lpMsgBuf);
    return errorMsg;
}


#else

#endif
}
