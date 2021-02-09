#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "EActorPerceptionSensitivity.h"
#include "ECCLeeState.h"

class ZActor;

class ZSequenceActor
{
public:
    TEntityRef<ZActor> m_pActor;
};

class alignas(4) ZSequenceControllerEntity : ZEntityImpl
{
public:
    TEntityRef<ISequenceEntity> m_pSequence;
    bool m_bPauseWaypointBehavior;
    bool m_bItemGlowEnabled;
    EActorPerceptionSensitivity m_ePerceptionSensitivity;
    bool m_bEnableAmbientLookat;
    TArray<ZSequenceActor*> m_SequenceActors;
    ECCLeeState m_State;
    float m_fValidateTime;
    __int8 m_bActivatedByIEntity : 1;
};
