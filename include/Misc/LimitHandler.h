#pragma once

#include "GMemoryHeap.h"

class LimitHandler
{
public:
    virtual ~LimitHandler();
    virtual bool OnExceedLimit(GMemoryHeap*, unsigned int);
    virtual void OnFreeSegment(GMemoryHeap*, unsigned int);
};
