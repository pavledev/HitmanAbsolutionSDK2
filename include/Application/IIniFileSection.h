#pragma once

#include "ZString.h"
#include "TEnumerator.h"

class IIniFileSection
{
public:
    virtual ~IIniFileSection();
    virtual ZString* GetName(ZString* result);
    virtual ZString* GetValue(ZString* result, const ZString*);
    virtual TEnumerator<ZString>* GetOptions(TEnumerator<ZString>* result);
};
