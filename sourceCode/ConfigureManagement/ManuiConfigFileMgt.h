#ifndef _CONFIGUREMANAGEMENT_MANUICONFIGFILEMGT_H_
#define _CONFIGUREMANAGEMENT_MANUICONFIGFILEMGT_H_
#include "ManuiConfig.h"
#include "Component.h"
#include "Macro.h"
#include <string>

namespace ConfigureManagement {

class ManuiConfigFileMgt
{
    std::string filePath_;
    ManuiConfig config_;
public:
    ManuiConfigFileMgt(const std::string& filePath);
    void openFileAndParse();
    void updateConfigure(const ManuiConfig& newConfig);
    void replaceConfigure(const ManuiConfig& newConfig);
private:
    void parsesRecord(std::vector<ManuiConfigRecord>& records, const std::string& line);
    void parsesSubRecord(ManuiConfigRecord& record, const std::string& subLine);
    void backup() const;
public:
     GETCLASSNAME(CpuInfoBriefly)
};

}
#endif // _CONFIGUREMANAGEMENT_MANUICONFIGFILEMGT_H_
