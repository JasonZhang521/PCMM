#include <vector>
#include "ChatManagementProcess.h"
#include "ChatMgtControl.h"
#include "ChatMgtConnectionAcceptor.h"
#include "ChatMgtConnectionReceiver.h"
#include "IpcClient.h"
#include "CoredumpConfig.h"
#include "Configure.h"
#include "NetworkConfig.h"
#include "LoopMain.h"

namespace ChatManagement {

ChatManagementProcess::ChatManagementProcess()
{

}

void ChatManagementProcess::process()
{
    CoredumpConfig::LimitSet();
    Configure::getInstance().setTraceLogFilePath("/opt/HongClusterMgt/log/ChatManagement.message.log");

    std::vector<std::string> chatServerIpPorts = ConfigureManagement::NetworkConfig::getChatServerIpPort();

    // create the Ipc server, will set the tcp acceptor later
    Network::IpSocketEndpoint localEndpoint(chatServerIpPorts[0]);
    // create the Cluster mananger control
    std::shared_ptr<ChatMgtControl> chatMgtController(new ChatMgtControl(localEndpoint));

    chatMgtController->startup();

    // run
    Core::LoopMain::instance().loopStart();
}

}
