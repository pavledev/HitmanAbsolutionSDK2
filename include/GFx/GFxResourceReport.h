#pragma once

#include "GString.h"
#include "GMemoryHeap.h"
#include "GStatBag.h"

class GFxResourceReport
{
public:
    virtual ~GFxResourceReport();
    virtual GString* GetResourceName(GString* result);
    virtual GMemoryHeap* GetResourceHeap();
    virtual void GetStats(GStatBag*, bool);
};
