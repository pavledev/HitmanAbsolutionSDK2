#pragma once

#include "GNewOverrideBase.h"
#include "GAtomicInt.h"
#include "GFxResourceKey.h"
#include "GFxResourceReport.h"

class GFxResourceLibBase;

class GFxResource : public GNewOverrideBase<2>
{
public:
    GAtomicInt<long> RefCount;
    GFxResourceLibBase* pLib;

    virtual ~GFxResource();
    virtual GFxResourceKey* GetKey(GFxResourceKey* result);
    virtual unsigned int GetResourceTypeCode();
    virtual GFxResourceReport* GetResourceReport();
};
