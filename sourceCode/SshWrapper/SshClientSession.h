#ifndef _SSHWRAPPER_SSHCLIENTSESSION_H_
#define _SSHWRAPPER_SSHCLIENTSESSION_H_
#include "ISshSession.h"
#include <map>
#include <string>

struct ssh_session_struct;
typedef struct ssh_session_struct* ssh_session;

namespace SshWrapper
{
class SshClientSession : public ISshSession
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
	Configure configure_;
	ssh_session session_;
public:
	SshClientSession(const Configure& configure);
	virtual ~SshClientSession();

	void configure(const Configure& config);
protected:
	virtual bool setup();
	virtual bool shutdown();
private:
	void setOptions();
	bool connect();
	void disconnect();
	bool verifyKnownhost();
	bool verifyUser();
};

}
#endif
