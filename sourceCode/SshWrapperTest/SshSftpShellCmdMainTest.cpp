#include "SshClient.h"
#include "SshClientSession.h"
#include "SshShellChannel.h"
#include "SshFtpSession.h"
#include <SshConfigure.h>
#include "libssh/libssh.h"
#include <iostream>
#include <string>

using namespace SshWrapper;
int main(int argc, char *argv[])
{
    std::cout << "start" << std::endl;
    SshConfigure configure;
    configure.user = "test";
    configure.password = "test";
    configure.host = "192.168.5.138";
    configure.port = 22;
    configure.verbosity = SSH_LOG_PROTOCOL;
    configure.unknownHostContinue = true;
    ssh_session session = ssh_new();
    std::cout << "step 1" << std::endl;
    SshClientSession* clientSession = new SshClientSession(session, configure);
    std::cout << "step 2" << std::endl;
    ISshClient* client = new SshClient(clientSession);
    std::cout << "step 4" << std::endl;
    client->setup();
    std::string inputString;
    std::string outputString;
    client->startSftp();
    //client->putFile()
    client->shutdownSftp();
    client->shutdown();
    return 0;
}
