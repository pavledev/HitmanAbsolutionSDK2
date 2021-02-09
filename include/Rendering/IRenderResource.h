#pragma once

#include "IRenderRefCount.h"
#include "ERenderResourceType.h"

class IRenderResource : public IRenderRefCount
{
public:
    virtual ERenderResourceType GetResourceType();
};
