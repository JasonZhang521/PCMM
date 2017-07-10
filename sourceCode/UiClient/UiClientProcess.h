#ifndef UICLIENTPROCESS_H
#define UICLIENTPROCESS_H
#include "Component.h"
#include "Macro.h"
#include <thread>
namespace UiClient {
class UiClientProcess
{
    std::thread uiClientThread_;
public:
    UiClientProcess();
    ~UiClientProcess();
    void start();
private:
    void process();
public:
     GETCLASSNAME(UiClientProcess)
};
}
#endif // UICLIENTPROCESS_H
