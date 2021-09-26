#pragma once

#include "ZSpatialEntity.h"
#include "DifficultyLevelEnum.h"
#include "EActorGroup.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZAgitatedGuardPointEntity : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bEnabled;
	DifficultyLevelEnum m_eMinDifficulty;
	bool m_bAllowActorGroupA;
	bool m_bAllowActorGroupB;
	bool m_bAllowActorGroupC;
	bool m_bAllowActorGroupD;

	static SComponentMapEntry s_componentMap[0];

	~ZAgitatedGuardPointEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZAgitatedGuardPointEntity() = default;
	static void RegisterType();
	ZAgitatedGuardPointEntity(ZComponentCreateInfo& info);
	bool IsEnabled() const;
	bool AllowActorGroup(EActorGroup group);
	void OnEnable();
	void OnDisable();
	DifficultyLevelEnum GetMinDifficulty() const;
};
