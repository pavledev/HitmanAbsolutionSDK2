#pragma once

#include "ZEntityImpl.h"
#include "SActorNoise.h"

class ZCloseCombatDef : public ZEntityImpl
{
public:
    TArray<SActorNoise> m_ActorNoiseList;
};
