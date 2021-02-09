#pragma once

#include "GMemoryHeap.h"

class HeapTracer
{
public:
    virtual ~HeapTracer();
    virtual void OnCreateHeap(const GMemoryHeap*);
    virtual void OnDestroyHeap(const GMemoryHeap*);
    virtual void OnAlloc(const GMemoryHeap*, unsigned int, unsigned int, unsigned int, const void*);
    virtual void OnRealloc(const GMemoryHeap*, const void*, unsigned int, const void*);
    virtual void OnFree(const GMemoryHeap*, const void*);
};
