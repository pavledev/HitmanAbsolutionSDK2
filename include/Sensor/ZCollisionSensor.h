#pragma once

#include "ZEvent.h"
#include "TEntityRef.h"
#include "ZActor.h"

class ZCollisionSensor
{
public:
    ZEvent<TEntityRef<ZActor>, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_ActorStaticCollisionEvent;

    virtual ~ZCollisionSensor();
};
