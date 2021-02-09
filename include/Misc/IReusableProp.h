#pragma once

class IReusableProp
{
public:
    virtual ~IReusableProp();
    virtual void UseOnce();
    virtual void ResetUsedFlag();
    virtual bool IsUsed();
};
