#pragma once

#include "SBehaviorBase.h"
#include "TArray.h"
#include "TEntityRef.h"
#include "ZWaypointEntity.h"
#include "EMoveSpeed.h"

class ZWaypointBehaviorEntity;

class SBehavior_Waypoint : public SBehaviorBase
{
public:
    TArray<TEntityRef<ZWaypointEntity>> m_aWaypoints;
    TEntityRef<ZWaypointBehaviorEntity> m_pBehaviorEntity;
    EActorEmotionState m_eEmotionState;
    EMoveSpeed m_eMoveSpeed;
};
