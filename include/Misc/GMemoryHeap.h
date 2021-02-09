#pragma once

#include "GListNode.h"
#include "HeapInfo.h"
#include "GList.h"
#include "GLock.h"
#include "GSysAllocPaged.h"
#include "HeapDesc.h"
#include "LimitHandler.h"
#include "GAllocDebugInfo.h"
#include "GStatBag.h"
#include "RootStats.h"
#include "HeapTracer.h"

class alignas(4) GMemoryHeap : public GListNode<GMemoryHeap>
{
public:
    unsigned int SelfSize;
    volatile unsigned int RefCount;
    unsigned int OwnerThreadId;
    void* pAutoRelease;
    HeapInfo Info;
    GList<GMemoryHeap> ChildHeaps;
    GLock HeapLock;
    bool UseLocks;
    bool TrackDebugInfo;

    virtual ~GMemoryHeap();
    virtual void CreateArena(unsigned int, GSysAllocPaged*);
    virtual void DestroyArena(unsigned int);
    virtual bool ArenaIsEmpty(unsigned int);
    virtual GMemoryHeap* CreateHeap(const char*, const HeapDesc*);
    virtual void SetLimitHandler(LimitHandler*);
    virtual void SetLimit(unsigned int);
    virtual void AddRef();
    virtual void Release();
    virtual void* Alloc(unsigned int, unsigned int, const GAllocDebugInfo*);
    virtual void* Alloc(unsigned int, const GAllocDebugInfo*);
    virtual void* Realloc(void*, unsigned int);
    virtual void Free(void*);
    virtual void* AllocAutoHeap(const void*, unsigned int, unsigned int, const GAllocDebugInfo*);
    virtual void* AllocAutoHeap(const void*, unsigned int, const GAllocDebugInfo*);
    virtual GMemoryHeap* GetAllocHeap(const void*);
    virtual unsigned int GetUsableSize(const void*);
    virtual void* AllocSysDirect(unsigned int);
    virtual void FreeSysDirect(void*, unsigned int);
    virtual bool GetStats(GStatBag*);
    virtual unsigned int GetFootprint();
    virtual unsigned int GetTotalFootprint();
    virtual unsigned int GetUsedSpace();
    virtual unsigned int GetTotalUsedSpace();
    virtual void GetRootStats(RootStats*);
    virtual void VisitMem(struct GHeapMemVisitor*, unsigned int);
    virtual void VisitRootSegments(struct GHeapSegVisitor*);
    virtual void VisitHeapSegments(struct GHeapSegVisitor*);
    virtual void SetTracer(HeapTracer*);
    virtual void destroyItself();
    virtual void ultimateCheck();
    virtual void releaseCachedMem();
    virtual bool dumpMemoryLeaks();
    virtual void checkIntegrity();
    virtual void getUserDebugStats(RootStats*);
};
