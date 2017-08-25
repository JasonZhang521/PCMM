<<<<<<< HEAD
#ifndef _CONFIGUREMGTMESSAGE_MAUICONFIGURATIONACQUIRERESPONSE_H_
#define _CONFIGUREMGTMESSAGE_MAUICONFIGURATIONACQUIRERESPONSE_H_
=======
#ifndef MANUICONFIGURATIONACQUIRERESPONSE_H
#define MANUICONFIGURATIONACQUIRERESPONSE_H
>>>>>>> 6b14ce4... Configuration Message (Maui request and response)
#include "IConfigureMgtMessage.h"
#include "MauiConfig.h"

namespace ConfigureMgtMessage {

class MauiConfigurationAcquireResponse : public IConfigureMgtMessage
{
    ConfigureManagement::MauiConfig mauiConfig_;
public:
    MauiConfigurationAcquireResponse();
    ~MauiConfigurationAcquireResponse();
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);

    virtual IpcMessage::IpcConfigureMgtMessageType getConfigureMgtType() const;
    virtual std::ostream& operator<< (std::ostream& os) const;

    void setMauiConfig(const ConfigureManagement::MauiConfig& config);
    const ConfigureManagement::MauiConfig&  getMauiConfig() const;
};

}

<<<<<<< HEAD
#endif // _CONFIGUREMGTMESSAGE_MAUICONFIGURATIONACQUIRERESPONSE_H_
=======
#endif // MANUICONFIGURATIONACQUIRERESPONSE_H
>>>>>>> 6b14ce4... Configuration Message (Maui request and response)
