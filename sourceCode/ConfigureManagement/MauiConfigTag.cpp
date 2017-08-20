#include "MauiConfigTag.h"
namespace ConfigureManagement {

const std::set<std::string> MauiConfigTag::SingleTag =
{
    "SERVERPORT"
    "JOBNODEMATCHPOLICY"
    "FSINTERVAL"
    "RMPOLLINTERVAL"
    "NODEACCESSPOLICY"
    "FSQOSWEIGHT"
    "LOGFILE"
    "SRCFGWEIGHT"
    "QUEUETIMEWEIGHT"
    "ENABLEMUITINODEJOBS"
    "ENABLEMULTIREQJOBS"
    "PREEMPTPOLICY"
    "GROUPWEIGHT"
    "LOGFILEMAXSIZE"
    "USERWEIGHT"
    "FSPOLICY"
    "SERVERMODE"
    "QOSWEIGHT"
    "BACKFILLPOLICY"
    "RESERVATIONPOLICY"
    "LOGLEVEL"
    "CLASSWEIGHT"
    "NODEALLOCATIONPOLICY"
    "CREDWEIGHT"
    "CONSUMEDWEIGHT"
    "LOGFILEROLLDEPTH"
    "DEFERTIME"
    "ADMIN1"
    "NODEAVAILABILITYPOLICY"
};

const std::set<std::string> MauiConfigTag::MultiTag =
{
    "RMCFG",
    "USERCFG",
    "QOSCFG",
    "CLASSCFG",
    "NODECFG",
    "SCHEDCFG"
};

const std::map<std::string, std::set<std::string> > SubTags =
{
    {"RMCFG", {"RESOURCETYPE", "CLUSTERQUERYURL", "HOST", "TYPE"}},
    {"USERCFG", {"MAXPROC", "MAXNODE", "MAXJOB"}},
    {"QOSCFG", {"QFLAGS"}},
    {"CLASSCFG", {"PRIORITY"}},
    {"NODECFG", {"INFINITEPRIO", "PRIORITYF", "RESCPUPGPU"}},
    {"SCHEDCFG", {"MODE", "SERVER"}}
};


MauiConfigTag::MauiConfigTag()
{

}

}
