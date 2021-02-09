#pragma once

#include "EReadBufferType.h"
#include "IJobProgram.h"

class IJob
{
public:
    virtual bool IsJobDone();
    virtual void WaitJobDone();
    virtual unsigned __int64 GetBookmark();
    virtual void SetReadBuffer(unsigned int, const void*, unsigned int, EReadBufferType);
    virtual void SetWriteBuffer(void*, unsigned int);
    virtual void SetCachedData(unsigned int, const void*, unsigned int);
    virtual void SetUserData(const void*, unsigned int);
    virtual void SetScratchSize(unsigned int);
    virtual void SetJobProgram(IJobProgram*, unsigned int);
    virtual void* GetReadBuffer(unsigned int);
    virtual unsigned int GetReadBufferSize(unsigned int);
    virtual void* GetWriteBuffer();
    virtual unsigned int GetWriteBufferSize();
    virtual const void* GetCachedData(unsigned int);
    virtual unsigned int GetCachedDataSize(unsigned int);
    virtual const void* GetUserData();
    virtual ~IJob();
};
