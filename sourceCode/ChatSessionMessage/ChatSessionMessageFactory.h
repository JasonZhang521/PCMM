#ifndef CHATSESSIONMESSAGEFACTORY_H
#define CHATSESSIONMESSAGEFACTORY_H
#include "IIpcMessageFactory.h"

namespace ChatSessionMessage {
class ChatSessionMessageFactory : public IpcMessage::IIpcMessageFactory
{
public:
    ChatSessionMessageFactory();
    virtual ~ChatSessionMessageFactory();
    virtual IpcMessage::IIpcMessage* createMessage(IpcMessage::IpcMessageApplicationIntType type) const;
};
}

#endif // CHATSESSIONMESSAGEFACTORY_H
