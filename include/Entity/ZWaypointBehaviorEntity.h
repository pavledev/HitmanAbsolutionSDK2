#pragma once

#include "ZSingleBehaviorEntityWrapper.h"
#include "SBehavior_Waypoint.h"
#include "EMoveSpeed.h"

class ZWaypointBehaviorEntity : public ZSingleBehaviorEntityWrapper
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	SBehavior_Waypoint m_behavior;
	TArray<TEntityRef<ZWaypointEntity>> m_aWayPoints;
	bool m_bOnlyActs;
	EActorEmotionState m_eEmotionState;
	EMoveSpeed m_eMoveSpeed;

	static SComponentMapEntry s_componentMap[0];

	~ZWaypointBehaviorEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	virtual void OnActiveBehaviorStarted();
	virtual void OnActiveBehaviorEnded();

	ZWaypointBehaviorEntity() = default;
	static void RegisterType();
	ZWaypointBehaviorEntity(ZComponentCreateInfo& info);
	SBehaviorBase* GetCompiledBehavior();
	bool GetOnlyActs();
	void WayPointsChanged();
};
