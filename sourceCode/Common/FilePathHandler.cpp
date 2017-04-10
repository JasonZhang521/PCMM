#include "FilePathHandler.h"

FilePathHandler::FilePathHandler()
{

}

std::string FilePathHandler::getFileName(const std::string& fullPath)
{
    size_t pos = fullPath.rfind('/');
    if (pos == std::string::npos)
    {
        pos = fullPath.rfind('\\');
    }

    if (pos == std::string::npos)
    {
        return fullPath;
    }
    else
    {
        return fullPath.substr(pos);
    }
}

std::string FilePathHandler::getFileDir(const std::string& fullPath)
{
    size_t pos = fullPath.rfind('/');
    if (pos == std::string::npos)
    {
        pos = fullPath.rfind('\\');
    }

    if (pos == std::string::npos)
    {
        return fullPath;
    }
    else
    {
        return fullPath.substr(0, pos);
    }
}
