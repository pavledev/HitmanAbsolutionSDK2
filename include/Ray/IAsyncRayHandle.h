#pragma once

#include "ZRayQueryInput.h"
#include "ZRayQueryOutput.h"

class IAsyncRayHandle
{
public:
    virtual bool IsReady();
    virtual void Release();
    virtual ZRayQueryInput* GetRayCastInput();
    virtual ZRayQueryOutput* GetRayCastOutput();
    virtual ~IAsyncRayHandle();
};