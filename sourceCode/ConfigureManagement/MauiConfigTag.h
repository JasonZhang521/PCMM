#ifndef MAUICONFIGTAG_H
#define MAUICONFIGTAG_H
#include <set>
#include <map>

namespace ConfigureManagement {

class MauiConfigTag
{
    static const std::set<std::string> SingleTag;
    static const std::set<std::string> MultiTag;
    static const std::map<std::string, std::set<std::string> > SubTags;
public:
    MauiConfigTag();
};

}

#endif // MAUICONFIGTAG_H
