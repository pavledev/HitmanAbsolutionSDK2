#pragma once

#include "IJob.h"

class IJobChain
{
public:
    virtual ~IJobChain();
    virtual IJob* CreateJob(unsigned int, unsigned int);
    virtual IJob* CreateJobInPlace(void*, unsigned int, unsigned int);
    virtual unsigned __int64 AddJob(IJob*);
    virtual unsigned __int64 AddJobsBulk(IJob**, unsigned int);
    virtual unsigned __int64 AddFlush();
    virtual void WaitAllDone();
};
