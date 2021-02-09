#pragma once

#include "ZEntityImpl.h"
#include "IMorphemeCutSequenceAnimatable.h"
#include "ISoundPlayable.h"
#include "ZActor.h"
#include "EActorPerceptionSensitivity.h"
#include "EActorEmotionState.h"
#include "EGameTension.h"
#include "ZActorsSequence.h"
#include "ZWaypointEntity.h"

class ZSequenceActor : public ZEntityImpl, public IMorphemeCutSequenceAnimatable, public ISoundPlayable
{
public:
    TEntityRef<ZActor> m_pActor;
    float m_fDistanceThreshold;
    bool m_bIsMandatoryActor;
    bool m_bShouldHaveReachedWaypoint;
    bool m_bEnableAmbientLookAt;
    EActorPerceptionSensitivity m_ePerceptionSensitivity;
    float m_fUpperBodyOnly;
    EActorEmotionState m_eRequiredEmotionState;
    EGameTension m_eMaximumGameTension;
    bool m_bStopActsAtFullBody;
    bool m_bStayAtWaypointTillSequenceEnds;
    bool m_bWaitForSequenceEvenIfDoneWithAct;
    bool m_bProjectToGround;
    __int8 m_bWithinDistance : 1;
    __int8 m_bHasReachedWayPoint : 1;
    __int8 m_bIsPlayingSequence : 1;
    __int8 m_bHasPlayedSequence : 1;
    __int8 m_bHasLeftSequence : 1;
    __int8 m_bHasCompletedLeadIn : 1;
    __int8 m_bHasStartedLeadOut : 1;
    __int8 m_bHasLeadinLeadout : 1;
    __int8 m_bIsPreviewing : 1;
    __int8 m_bIsRunningWaypointBehavior : 1;
    __int8 m_bExternallyBinded : 1;
    __int8 m_bShouldntStopAct : 1;
    ZActorsSequence* m_pActorsSequence;
    ZWaypointEntity* m_pWaypoint;
    SMatrix m_mTransformAtFullBody;
    SMatrix m_mTransformAtSequenceStart;
};
