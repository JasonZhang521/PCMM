#include "SshClient.h"
#include "SshConfigure.h"
#include "libssh/libssh.h"
#include <iostream>
#include <string>
using namespace SshWrapper;;
int main()
{
	SshConfigure configure;
	configure.user = "test";
	configure.password = "test";
	configure.host = "localhost";
	configure.port = 22;
	configure.verbosity = SSH_LOG_PROTOCOL;
	configure.unknownHostContinue = true;
	ISshClient* client = new SshClient(configure);
	client->setup();
	std::string inputString;
	std::string outputString;
	client->startShell();
	while (inputString != std::string("exit"))
	{
		char ch[256];
		std::fill(ch, ch + 256, 0);
		std::cout << "Input command:";
		std::cin.getline(ch, 255);
		std::cout << "[" << ch << "]" << std::endl;
		inputString = ch;
        client->executeShellCommand(inputString, outputString);
		std::cout << outputString << std::endl;
	}
    client->shutdownShell();
	client->shutdown();
	return 0;
}
