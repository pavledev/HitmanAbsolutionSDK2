#pragma once

#include "ZActorAnimationProgram.h"

class alignas(4) ZCarryCivilianLocomotion : public ZActorAnimationProgram
{
public:
    ZString m_sAnimAction;
    ZString m_sAnimStates;
    TEntityRef<ZHitman5> m_pHitman;
    SActorHSState::eActorHSState m_eCurrentHSState;
    ZGameTime m_tEnterTime;
    SMatrix43 m_mvEnterMatPos;
    ZActor* m_pActor;
    bool m_bDirectToStandIdle;
};
