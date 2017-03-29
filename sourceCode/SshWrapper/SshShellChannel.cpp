#include <string>
#include <map>
#include <sstream>
#include <libssh/libssh.h>
#include "App.h"
#include "Trace.h"
#include "SshShellChannel.h"

namespace SshWrapper
{

SshShellChannel::SshShellChannel(ssh_session session)
: channel_(ssh_channel_new(session))
{
	if (session == NULL)
	{
		TRACE_WARNING("Session is NULL when initial shell channel!");
		App::ExitNormal();
	}

	if (channel_ == NULL)
	{
		TRACE_WARNING("Channel is NULL when initial shell channel!");
		App::ExitNormal();
	}
}

SshShellChannel::~SshShellChannel()
{
	ssh_channel_free(channel_);
}

bool SshShellChannel::setup()
{
	int rc = ssh_channel_open_session(channel_);
	if (rc != SSH_OK)
	{
		TRACE_WARNING("Error open new Channel: rc = " << rc << ", error info:" << ssh_get_error(session_)); 
		return false;
	}
	return true;
}

bool SshShellChannel::shutdown()
{
	ssh_channel_close(channel_);
}

bool SshShellChannel::executeCommand(const std::string& cmd, std::string& cmdOutput)
{
	int rc = ssh_channel_request_exec(channel_, cmd.c_str());
	if (rc != SSH_OK)
	{
		TRACE_WARNING("Error execute shell: rc = " << rc << ", error info:" << ssh_get_error(channel_));
		return false;
	}

    char buffer[256];                                                                                             
	int nbytes = ssh_channel_read(channel_, buffer, sizeof(buffer), 0);                                        
	while (nbytes > 0)                                                                                            
	{                                                                                                             
	    buffer[nbytes] = 0;                                                                                   
		sstr << buffer;                                                                                       
		nbytes = ssh_channel_read(channel_, buffer, sizeof(buffer), 0);                                    
	}

	if (nbytes < 0)
	{
		TRACE_WARNING("Read channel error, readed bytes = " << nbytes << "error info:" << ssh_get_error(channel_));
		return false;
	}

	cmdOutput = sstr.str(); 
    ssh_channel_send_eof(channel_);
	return true;
}

}
