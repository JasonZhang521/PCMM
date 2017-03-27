#include <iostream>
#include <string>
#include <libssh/libssh.h>
#include "SshClient.h"
#include "Configure.h"
#include "Trace.h"

int main()
{

    Configure::getInstance().setTraceLogTarget(TRACE_LOG_TO_FILE);
	std::cout << "SSH testing" << std::endl;
	// put your user
	std::string user("user");
	// put your password here
	std::string password("password");
    //SshClient client(true, user, password, "localhost", SSH_LOG_FUNCTIONS, 22);
	SshClient client(true, user, password, "localhost", SSH_LOG_PROTOCOL, 22);
    client.setup();
	std::cout << "execute ps -aux" << std::endl;
	std::string cli("ps -aux | grep ps");
	std::string cliResult;
	client.executeCliCommand(cli, cliResult);
	std::cout << cliResult << std::endl;
	std::cout << "execute ll -a" << std::endl;
	cli = "ls -a";
	client.executeCliCommand(cli, cliResult);
	std::cout << cliResult.size() << "\n"  << cliResult << std::endl;
    client.shutdown();
	return 0;
}
