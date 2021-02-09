#pragma once

#include "TMaxArray.h"
#include "SSocialActorData.h"
#include "ZSocialSensorDef.h"

class alignas(8) ZSocialSensor
{
public:
    TMaxArray<SSocialActorData, 16> m_aSocialActors;
    TEntityRef<ZHitman5> m_pHitman;
    TEntityRef<ZSocialSensorDef> m_pSensorDef;
    TArrayRef<TEntityRef<ZActor> > m_aActors;
    SCombatTimer m_tCooldownRunning;
    SCombatTimer m_tCooldownStanding;
    SCombatTimer m_tCooldownGreeting;
    SCombatTimer m_tCooldownSilly;
    int m_nActorCandidate;
};
