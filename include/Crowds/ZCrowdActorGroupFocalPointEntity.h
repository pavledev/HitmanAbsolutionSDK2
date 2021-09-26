#pragma once

#include "ZSpatialEntity.h"
#include "ZResourcePtr.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZCrowdActorGroupFocalPointEntity : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZResourcePtr m_pHelper;

	static SComponentMapEntry s_componentMap[0];

	~ZCrowdActorGroupFocalPointEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZCrowdActorGroupFocalPointEntity() = default;
	static void RegisterType();
	ZCrowdActorGroupFocalPointEntity(ZComponentCreateInfo& info);
	void OnHelperChanged();
};
