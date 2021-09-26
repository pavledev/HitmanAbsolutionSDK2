#pragma once

#include "ZSpatialEntity.h"
#include "DifficultyLevelEnum.h"
#include "EGuardPointType.h"
#include "TMaxArray.h"
#include "ZGameTime.h"
#include "EActorGroup.h"
#include "SComponentMapEntry.h"
#include "TEntityRef.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZHM5CoverPlane;
class ZString;
struct STypeID;

class ZGuardPointEntity : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bEnabled;
	DifficultyLevelEnum m_eMinDifficulty;
	EGuardPointType m_eType;
	unsigned int m_nMaxNumberOfGuards;
	float m_fRadius;
	float m_fHeight;
	TEntityRef<ZSpatialEntity> m_rHoldTowardPos;
	bool m_bAllowActorGroupA;
	bool m_bAllowActorGroupB;
	bool m_bAllowActorGroupC;
	bool m_bAllowActorGroupD;
	TMaxArray<ZHM5CoverPlane*, 64> m_covers;
	bool m_bHoldValid;
	bool m_bStreamedIn;
	ZGameTime m_tEnableChangeTime;

	static SComponentMapEntry s_componentMap[0];

	~ZGuardPointEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	ZGuardPointEntity() = default;
	static void RegisterType();
	ZGuardPointEntity(ZComponentCreateInfo& info);
	void OnEnable();
	void OnDisable();
	bool AllowActorGroup(EActorGroup group);
	bool IsEnabled() const;
	bool IsHoldEnabled() const;
	bool IsCombatEnabled() const;
	bool HasEnableChanged();
	ZGameTime GetEnableChangeTime();
	int GetMaxNumberOfGuards() const;
	const TMaxArray<ZHM5CoverPlane*, 64>& GetCovers() const;
	float GetRadius();
	float GetHeight();
	TEntityRef<ZSpatialEntity> GetHoldTowardPos() const;
	bool IsCoverPlaneInRange(ZHM5CoverPlane* pCover) const;
};
