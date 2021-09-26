#pragma once

#include "SBehaviorBase.h"
#include "TArray.h"
#include "TEntityRef.h"
#include "EMoveSpeed.h"
#include "EActorEmotionState.h"

class ZWaypointBehaviorEntity;
class ZActiveBehavior;
struct SBehaviorTreeContext;
class ZWaypointEntity;

struct SBehavior_Waypoint : SBehaviorBase
{
	TArray<TEntityRef<ZWaypointEntity>> m_aWaypoints;
	TEntityRef<ZWaypointBehaviorEntity> m_pBehaviorEntity;
	EActorEmotionState m_eEmotionState;
	EMoveSpeed m_eMoveSpeed;

	ZActiveBehavior* Initialize(const SBehaviorTreeContext& context);
	SBehavior_Waypoint(const SBehavior_Waypoint& __that);
	SBehavior_Waypoint() = default;
	void OnActiveBehaviorStarted();
	void OnActiveBehaviorEnded();
	~SBehavior_Waypoint() = default;
	SBehavior_Waypoint& operator=(const SBehavior_Waypoint& __that);
};
