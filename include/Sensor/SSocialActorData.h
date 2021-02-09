#pragma once

#include "TEntityRef.h"
#include "ZActor.h"
#include "ZSocialActor.h"
#include "ESocialActorState.h"
#include "ESocialInteractionType.h"
#include "SCombatTimer.h"

class SSocialActorData
{
public:
    TEntityRef<ZActor> m_pActor;
    TEntityRef<ZSocialActor> m_pSocialActorEntity;
    TEntityRef<ZActor> m_pInteractActor;
    TEntityRef<ZHM5BaseCharacter> m_pLastLookAt;
    ESocialActorState m_eState;
    ESocialInteractionType m_eInteractionType;
    int m_iNextActorIndex;
    float m_tHitmanStandingTime;
    ZGameTime m_tHitmanRunningTime;
    float m_tHitmanSillyTime;
    SCombatTimer m_tCooldown;
    SCombatTimer m_tBored;
    bool m_bAmbientLookAt;
    bool m_bGreeting;
    bool m_bCanGreet;
    bool m_bNewCandidate;
};
