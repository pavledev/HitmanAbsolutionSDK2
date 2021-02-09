#pragma once

#include "ZActorAnimationProgram.h"
#include "TEntityRef.h"
#include "ZHitman5.h"
#include "SActorHSState.h"
#include "ZActor.h"

class alignas(4) ZHumanShieldLocomotion : public ZActorAnimationProgram
{
public:
    ZString m_sAnimAction;
    ZString m_sAnimStates;
    TEntityRef<ZHitman5> m_pHitman;
    SActorHSState::eActorHSState m_eCurrentHSState;
    ZActor* m_pActor;
    float m_fBlendInTime;
};
