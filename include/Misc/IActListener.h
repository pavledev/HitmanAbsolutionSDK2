#pragma once

#include "IComponentInterface.h"

class IActListener : public IComponentInterface
{
public:
    virtual void OnActStart();
    virtual void OnActFinished();
    virtual void OnActLoopStart();
    virtual void OnActInFullbody();
    virtual void OnActBehaviorEvent(unsigned int, float);
};
