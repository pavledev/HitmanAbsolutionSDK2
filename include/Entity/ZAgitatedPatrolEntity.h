#pragma once

#include "ZEntityImpl.h"
#include "DifficultyLevelEnum.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "ZVariantRef.h"

class ZAgitatedWaypointEntity;
class ZComponentCreateInfo;
struct STypeID;
template <class T> class TEntityRef;

class ZAgitatedPatrolEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TArray<TEntityRef<ZAgitatedWaypointEntity>> m_waypoints;
	bool m_bEnabled;
	DifficultyLevelEnum m_eMinDifficulty;
	unsigned int m_nMaxNumberOfGuards;

	static SComponentMapEntry s_componentMap[0];

	~ZAgitatedPatrolEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZAgitatedPatrolEntity() = default;
	static void RegisterType();
	ZAgitatedPatrolEntity(ZComponentCreateInfo& info);
	TArrayRef<TEntityRef<ZAgitatedWaypointEntity>> GetWaypoints() const;
	bool IsEnabled() const;
	unsigned int GetMaxNumberOfGuards() const;
	void OnEnable();
	void OnDisable();
};
