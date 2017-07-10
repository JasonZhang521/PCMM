#include "UiClientProcess.h"
int main(int argc, char**argv)
{
    static_cast<void>(argc);
    static_cast<void>(argv);
    UiClient::UiClientProcess process;
    process.start();
    return 0;
}
