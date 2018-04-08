#include "ChatManagementProcess.h"
int main(int argc, char**argv)
{
    static_cast<void>(argc);
    static_cast<void>(argv);
    ChatManagement::ChatManagementProcess process;
    process.process();
    return 0;
}
