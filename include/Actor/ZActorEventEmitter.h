#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZActor.h"

class alignas(4) ZActorEventEmitter : public ZEntityImpl
{
public:
    ZEntityRef m_pActor;
    TEntityRef<ZActor> m_pActorInternal;
    bool m_bRegistered;
};
