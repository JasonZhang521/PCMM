#include "SshClient.h"
#include "SshClientSession.h"
#include "App.h"
#include "Trace.h"

namespace SshWrapper
{

SshClient::SshClient(ISshClientSession* session)
: session_(session)
{
	if (session_ == NULL)
	{
	    TRACE_WARNING("Session is NULL when initial shell channel!");
		App::ExitNormal();
	}
}

SshClient::~SshClient()
{
	if (session_ != NULL)
	{
		delete session_;
	}
}

bool SshClient::setup()
{
	return session_->setup();
}
bool SshClient::shutdown()
{
	return session_->shutdown();
}
bool SshClient::startShell()
{
	return session_->startShellChannel();
}
bool SshClient::shutdownShell()
{
	return session_->shutdownShellChannel();
}
bool SshClient::executeShellCommand(const std::string& cmd, std::string& cmdOutput)
{
	return session_->executeShellCommand(cmd, cmdOutput);
}

}
