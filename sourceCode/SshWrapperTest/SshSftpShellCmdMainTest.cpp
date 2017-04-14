#include "SshClient.h"
#include "SshClientSession.h"
#include "SshShellChannel.h"
#include "SshFtpSession.h"
#include <SshConfigure.h>
#include "SftpDirAttribute.h"
#include "libssh/libssh.h"
#include <iostream>
#include <string>

using namespace SshWrapper;
int main(int argc, char *argv[])
{
    static_cast<void>(argc);
    static_cast<void>(argv);
    std::string user, password, hostname;
    // std::cout << "Input host:";
    // std::cin >> hostname;
    hostname = "selnpcgwnx1000.seln.ete.ericsson.se";
    std::cout << "Input User:";
    std::cin >> user;
    std::cout << "Input password:";
    std::cin >> password;
    std::cout << "start" << std::endl;
    SshConfigure configure;
    configure.user = user;
    configure.password = password;
    configure.host = hostname;
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
    client->startSftp();
	std::cout << "Input cmd:\n"
		      << "(1) ls: list the Dir\n"
			  << "(2) put file: upload file\n"
			  << "(3) get file: download file\n";
		      
	std::string inputString;
	while (inputString != std::string("exit"))
	{
        char ch[256];
        std::fill(ch, ch + 256, 0);
		std::cout << "Input command:";
		std::cin.getline(ch, 255);
		std::cout << "[" << ch << "]" << std::endl;
		inputString = ch;

		if (inputString == std::string("ls"))
		{
	        SftpDirAttributes attributes;
            client->listDir(std::string("/home/euwyzbc"), attributes);
	        std::cout << attributes << std::endl;
		}
		else if(inputString == std::string("get"))
		{
			//client->get();
		}
		else
		{
        }
	}
    //client->putFile()
    client->shutdownSftp();
    client->shutdown();
    return 0;
}
