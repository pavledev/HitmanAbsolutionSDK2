#pragma once

#include "TArrayRef.h"
#include "MR.h"

class IMorphemeEventConsumer
{
public:
    virtual void HandleAnimationEvents(const TArrayRef<MR::TriggeredEvent*>*, ZEntityRef);
    virtual const char* GetConsumerID();
    virtual void StopAll();
    virtual void Enable();
    virtual void Disable();
    virtual void CleanupCurrentEvents();
    virtual ~IMorphemeEventConsumer();
};
