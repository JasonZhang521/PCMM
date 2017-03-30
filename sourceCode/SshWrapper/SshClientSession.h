#ifndef _SSHWRAPPER_SSHCLIENTSESSION_H_
#define _SSHWRAPPER_SSHCLIENTSESSION_H_
#include "ISshClientSession.h"
#include <map>
#include <string>

struct ssh_session_struct;
typedef struct ssh_session_struct* ssh_session;
 
namespace SshWrapper
{
class ISshShellChannel;

class SshClientSession : public ISshClientSession
{
public:
    struct Configure
	{
		Configure();
		Configure(const Configure& config);
		Configure& operator=(const Configure& config);

        std::string user;
		std::string password;
		std::string host;
		int port;
		int verbosity;
		bool unknownHostContinue;
	};
private:
	ssh_session session_;
	Configure configure_;
    ISshShellChannel* shellChannel_;
public:
	SshClientSession(const Configure& configure);
	virtual ~SshClientSession();

	void configure(const Configure& config);
protected:
	virtual bool setup();
	virtual bool shutdown();
        virtual bool startShellChannel();
        virtual bool shutdownShellChannel();
        virtual bool executeShellCommand(const std::string& cmd, std::string& cmdOutput);
private:
	void setOptions();
	bool connect();
	void disconnect();
	bool verifyKnownhost();
	bool verifyUser();
};

}
#endif
