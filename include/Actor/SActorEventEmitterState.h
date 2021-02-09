#pragma once

#include "TEntityRef.h"
#include "ZActor.h"
#include "ZActorEventEmitter.h"

class SActorEventEmitterState
{
public:
    TEntityRef<ZActor> m_rActor;
    TMaxArray<ZActorEventEmitter*, 6> m_emitters;
    EGameTension m_eTension;
    __int8 m_bDead : 1;
    __int8 m_bArmed : 1;
    __int8 m_bWounded : 1;
    __int8 m_bSpeaking : 1;
    __int8 m_bInSequence : 1;
    __int8 m_bFirstHit : 1;
    __int8 m_bOnScreen : 1;
    __int8 m_bOutfitTaken : 1;
    __int8 m_bFirstOnScreen : 1;
    __int8 m_bFirstOnScreenSound : 1;
    __int8 m_bSBTimeAdded : 1;
    __int8 m_bSBTimeSubtracted : 1;
    __int8 m_bHumanShield : 1;
    __int8 m_bHitmanInSight : 1;
    __int8 m_bHitmanFullAttention : 1;
    __int8 m_bSBKillTagAdded : 1;
    float m_fSBActorSubtractReactTime;
    unsigned int m_nRayIndex;
    unsigned int m_nMissedRayTests;
    IAsyncRayHandle* m_pCollisionHandle;
};
