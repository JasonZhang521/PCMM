#include "ShellCommandOutputParse.h"
#include "RemoveCharacter.h"
#include <sstream>
#include <iostream>
namespace Environment {

ShellCommandOutputParse::ShellCommandOutputParse()
{

}

void ShellCommandOutputParse::ParseDuOutput(const CommandOutputString strs, DfOutputs& outPuts)
{
    RemoveCharacter remover;
    for (size_t i = 1; i < strs.size(); ++i)
    {
        DfOutput dfOutput;
        const std::string& online = strs[i];

        // delete the first and last space and tab
        remover.setCharacter(' ');
        std::string str = remover(online);
        remover.setCharacter('\t');
        str = remover(str);

        size_t firstSpace = str.find_first_of(' ');
        size_t firstTab = str.find_first_of('\t');
        size_t pos = firstSpace < firstTab ? firstSpace : firstTab;

        dfOutput.fileSystem = str.substr(0, pos);

        str = str.substr(pos, str.size() - pos);

        // delete the first and last space and tab
        remover.setCharacter(' ');
        str = remover(str);
        remover.setCharacter('\t');
        str = remover(str);

        firstSpace = str.find_first_of(' ');
        firstTab = str.find_first_of('\t');
        pos = firstSpace < firstTab ? firstSpace : firstTab;

        std::string oneKBlock = str.substr(0, pos);
		{
            std::stringstream ss;
            ss << oneKBlock;
            ss >> dfOutput.oneKBlock;
        }
        str = str.substr(pos, str.size() - pos);

        // delete the first and last space and tab
        remover.setCharacter(' ');
        str = remover(str);
        remover.setCharacter('\t');
        str = remover(str);

        firstSpace = str.find_first_of(' ');
        firstTab = str.find_first_of('\t');
        pos = firstSpace < firstTab ? firstSpace : firstTab;

        std::string used = str.substr(0, pos);
		{
            std::stringstream ss;
            ss << used;
            ss >> dfOutput.used;
        }
        str = str.substr(pos, str.size() - pos);

        // delete the first and last space and tab
        remover.setCharacter(' ');
        str = remover(str);
        remover.setCharacter('\t');
        str = remover(str);

        firstSpace = str.find_first_of(' ');
        firstTab = str.find_first_of('\t');
        pos = firstSpace < firstTab ? firstSpace : firstTab;

        std::string available = str.substr(0, pos);
		{
            std::stringstream ss;
            ss << available;
            ss >> dfOutput.available;
        }
        str = str.substr(pos, str.size() - pos);

        // delete the first and last space and tab
        remover.setCharacter(' ');
        str = remover(str);
        remover.setCharacter('\t');
        str = remover(str);

        firstSpace = str.find_first_of(' ');
        firstTab = str.find_first_of('\t');
        pos = firstSpace < firstTab ? firstSpace : firstTab;

        std::string pecentageUsed = str.substr(0, pos - 1);
		{
            std::stringstream ss;
            ss << pecentageUsed;
            ss >> dfOutput.pecentageUsed;
        }
        str = str.substr(pos, str.size() - pos);

        // delete the first and last space and tab
        remover.setCharacter(' ');
        str = remover(str);
        remover.setCharacter('\t');
        str = remover(str);

        firstSpace = str.find_first_of(' ');
        firstTab = str.find_first_of('\t');
        pos = firstSpace < firstTab ? firstSpace : firstTab;

        dfOutput.mountedOn = str.substr(0, pos - 1);

        outPuts.push_back(dfOutput);
    }
}

}
