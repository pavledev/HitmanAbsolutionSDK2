#pragma once

#include "TEntityRef.h"
#include "ZActor.h"
#include "MR.h"

class alignas(4) ZActiveBehavior
{
public:
    TEntityRef<ZActor> m_pActor;

    virtual ~ZActiveBehavior();
    virtual void OnAnimationEvents(const MR::TriggeredEventsBuffer*);
};
