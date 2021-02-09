#pragma once

#include "GSysAllocBase.h"

class GSysAllocPaged : public GSysAllocBase
{
public:
    struct alignas(4) Info
    {
        unsigned int MinAlign;
        unsigned int MaxAlign;
        unsigned int Granularity;
        unsigned int SysDirectThreshold;
        unsigned int MaxHeapGranularity;
        bool HasRealloc;
    };

    virtual void GetInfo(Info*);
    virtual void* Alloc(unsigned int, unsigned int);
    virtual bool Free(void*, unsigned int, unsigned int);
    virtual bool ReallocInPlace(void*, unsigned int, unsigned int, unsigned int);
    virtual void* AllocSysDirect(unsigned int, unsigned int, unsigned int*, unsigned int*);
    virtual bool FreeSysDirect(void*, unsigned int, unsigned int);
    virtual unsigned int GetBase();
    virtual unsigned int GetSize();
    virtual unsigned int GetFootprint();
    virtual unsigned int GetUsedSpace();
    virtual void VisitMem(struct GHeapMemVisitor*);
    virtual void VisitSegments(struct GHeapSegVisitor*, unsigned int, unsigned int);
};
