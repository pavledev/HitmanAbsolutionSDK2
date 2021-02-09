#pragma once

#include "ZSingleBehaviorEntityWrapper.h"
#include "SBehavior_Waypoint.h"
#include "EMoveSpeed.h"

class ZWaypointBehaviorEntity : public ZSingleBehaviorEntityWrapper
{
public:
    SBehavior_Waypoint m_behavior;
    TArray<TEntityRef<ZWaypointEntity> > m_aWayPoints;
    bool m_bOnlyActs;
    EActorEmotionState m_eEmotionState;
    EMoveSpeed m_eMoveSpeed;

    virtual void OnActiveBehaviorStarted();
    virtual void OnActiveBehaviorEnded();
};
