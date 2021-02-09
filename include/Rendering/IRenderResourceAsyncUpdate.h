#pragma once

#include "IRenderRefCount.h"

class IRenderResourceAsyncUpdate : public IRenderRefCount
{
public:
    virtual void Apply();
};
