#pragma once

#include "ZSpatialEntity.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZBoneEntity : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	int m_nBoneGlobalID;

	static SComponentMapEntry s_componentMap[0];

	~ZBoneEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZBoneEntity() = default;
	static void RegisterType();
	ZBoneEntity(ZComponentCreateInfo& Info);
	void SetBoneGlobalID(int nGlobalBoneID);
	int GetBoneGlobalID() const;
};
