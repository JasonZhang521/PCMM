#ifndef _CONFIGUREMANAGMENT_MAUICONFIG_H_
#define _CONFIGUREMANAGMENT_MAUICONFIG_H_
#include <stdint.h>
#include <string>



namespace ConfigureManagement {
class MauiConfig
{
    // SERVERPORT
    uint16_t serverPort_ = 0;
    // JOBNODEMATCHPOLICY
    std::string jobNodeMatchPolicy_;
    // FSINTERVAL (uint second, need to transfer to xx:xx:xx)
    uint32_t fsInterval_ = 0;
    // RMPOLLINTERVAL (uint second, need to transfer to xx:xx:xx)
    uint32_t rmPollInterval_ = 0;
    // NODEACCESSPOLICY
    std::string nodeAccessPolicy_;
    // FSQOSWEIGHT
    uint8_t fsQosWeight_ = 0;
    // LOGFILE
    std::string logFile_;
    // SRCFGWEIGHT
    uint8_t srcFgWeight_ = 0;
    // QUEUETIMEWEIGHT
    uint8_t queueTimeWeight_ = 0;
    // ENABLEMUITINODEJOBS
    bool enableMultiNodeJobs_ = false;
    // ENABLEMULTIREQJOBS
    bool enableMultiReqJobs_ = false;
    // PREEMPTPOLICY
    std::string preemptPolicy_;
    // GROUPWEIGHT
    uint8_t groupWeight_ = 0;
    // LOGFILEMAXSIZE
    uint32_t logFileMaxSize_ = 0;
    // USERWEIGHT
    uint8_t userWeight_ = 0;
    // FSPOLICY
    std::string fsPolicy_;
    // SERVERMODE
    std::string serverMode_;
    // QOSWEIGHT
    uint8_t qosWeight_ = 0;
    // BACKFILLPOLICY
    std::string backFillPolicy_;
    // RESERVATIONPOLICY
    std::string reservationPolicy_;
    // LOGLEVEL
    uint8_t logLevel_ = 0;
    // CLASSWEIGHT
    uint8_t classWeight_ = 0;
    // NODEALLOCATIONPOLICY
    std::string nodeAllocationPolicy_;
    // CREDWEIGHT
    uint8_t credWeight_ = 0;
    // CONSUMEDWEIGHT
    uint8_t consumedWeight_ = 0;
    // LOGFILEROLLDEPTH
    uint8_t logFileRollDepth_ = 0;
    // DEFERTIME
    uint32_t deferTime_ = 0;
    // ADMIN1
    std::string admin1_;

public:
    inline void setServerPort(uint16_t serverPort) {serverPort_ = serverPort;}
    inline uint16_t getServerPort() const {return serverPort_;}

    inline void setJobNodeMatchPolicy(const std::string& jobNodeMatchPolicy) {jobNodeMatchPolicy_ = jobNodeMatchPolicy;}
    inline const std::string& getJobNodeMatchPolicy() const {return jobNodeMatchPolicy_;}

    inline void setFsInterval(uint32_t fsInterval) {fsInterval_ = fsInterval;}
    inline uint32_t getFsInterval() const {return fsInterval_;}

    inline void setRmPollInterval(uint32_t rmPollInterval) {rmPollInterval_ = rmPollInterval;}
    inline uint32_t getRmPollInterval() const {return rmPollInterval_;}

    inline void setNodeAccessPolicy(const std::string& nodeAccessPolicy) {nodeAccessPolicy_ = nodeAccessPolicy;}
    inline const std::string& getNodeAccessPolicy() const {return nodeAccessPolicy_;}

    inline void setFsQosWeight(uint8_t fsQosWeight) {fsQosWeight_ = fsQosWeight;}
    inline uint8_t getFsQosWeight() const {return fsQosWeight_;}

    inline void setLogFile(const std::string& logFile) {logFile_ = logFile;}
    inline const std::string& getLogFile() const {return logFile_;}

    inline void setSrcFgWeight(uint8_t srcFgWeight) {srcFgWeight_ = srcFgWeight;}
    inline uint8_t getSrcFgWeight() const {return srcFgWeight_;}

    inline void setQueueTimeWeight(uint8_t queueTimeWeight) {queueTimeWeight_ = queueTimeWeight;}
    inline uint8_t getQueueTimeWeight() const {return queueTimeWeight_;}

    inline void enableMultiNodeJobs(bool enableMultiNodeJobs) {enableMultiNodeJobs_ = enableMultiNodeJobs;}
    inline bool isMultiNodeJobsEnable() const {return enableMultiNodeJobs_;}

    inline void enableMultiReqJobs(bool enable) {enableMultiReqJobs_ = enable;}
    inline bool isMultiReqJobsEnable() const {return enableMultiReqJobs_;}

    inline void setPreemptPolicy(const std::string& preemptPolicy) {preemptPolicy_ = preemptPolicy;}
    inline const std::string& getPreemptPolicy() const {return preemptPolicy_;}

    inline void setGroupWeight(uint8_t groupWeight) {groupWeight_ = groupWeight;}
    inline uint8_t getGroupWeight() const {return groupWeight_;}

    inline void setLogFileMaxSize(uint32_t logFileMaxSize) {logFileMaxSize_ = logFileMaxSize;}
    inline uint32_t getLogFileMaxSize() const {return logFileMaxSize_;}

    inline void setUserWeight(uint8_t userWeight) {userWeight_ = userWeight;}
    inline uint8_t getUserWeight() const {return userWeight_;}

    inline void setFsPolicy(const std::string& fsPolicy) {fsPolicy_ = fsPolicy;}
    inline const std::string& getFsPolicy() const {return fsPolicy_;}

    inline void setServerMode(const std::string& serverMode) {serverMode_ = serverMode;}
    inline const std::string& getServerMode() const {return serverMode_;}

    inline void setQosWeight(uint8_t qosWeight) {qosWeight_ = qosWeight;}
    inline uint8_t getQosWeight() const {return qosWeight_;}

    inline void setBackFillPolicy(const std::string& backFillPolicy) {backFillPolicy_ = backFillPolicy;}
    inline const std::string& getBackFillPolicy() const {return backFillPolicy_;}

    inline void setReservationPolicy(const std::string& reservationPolicy) {reservationPolicy_ = reservationPolicy;}
    inline const std::string& getReservationPolicy() const {return reservationPolicy_;}

    inline void setLogLevel(uint8_t logLevel) {logLevel_ = logLevel;}
    inline uint8_t getLogLevel() const {return logLevel_;}

    inline void setClassWeight(uint8_t classWeight) {classWeight_ = classWeight;}
    inline uint8_t getClassWeight() const {return classWeight_;}

    inline void setNodeAllocationPolicy(const std::string& nodeAllocationPolicy) {nodeAllocationPolicy_ = nodeAllocationPolicy;}
    inline const std::string& getNodeAllocationPolicy() const {return nodeAllocationPolicy_;}

    inline void setCredWeight(uint8_t credWeight) {credWeight_ = credWeight;}
    inline uint8_t getCredWeight() const {return credWeight_;}

    inline void setConsumedWeight(uint8_t consumedWeight) {consumedWeight_ = consumedWeight;}
    inline uint8_t getConsumedWeight() const {return consumedWeight_;}

    inline void setLogFileRollDepth(uint8_t logFileRollDepth) {logFileRollDepth_ = logFileRollDepth;}
    inline uint8_t getLogFileRollDepth() const {return logFileRollDepth_;}

    inline void setDeferTime(uint32_t deferTime) {deferTime_ = deferTime;}
    inline uint32_t getDeferTime() const {return deferTime_;}

    inline void setAdmin1(const std::string& admin1) {admin1_ = admin1;}
    inline const std::string& getAdmin1() const {return admin1_;}

public:
    MauiConfig();
    MauiConfig(const MauiConfig& config);
};
}

#endif // _CONFIGUREMANAGMENT_MAUICONFIG_H_
