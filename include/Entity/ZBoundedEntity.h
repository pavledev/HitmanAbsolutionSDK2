#pragma once

#include "ZSpatialEntity.h"
#include "SComponentMapEntry.h"
#include "SVector3.h"
#include "ZVariantRef.h"
#include "float4.h"

class ZComponentCreateInfo;
struct STypeID;

class ZBoundedEntity : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	SVector3 m_vCenter;
	SVector3 m_vHalfSize;

	static SComponentMapEntry s_componentMap[0];

	~ZBoundedEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	const ZBoundedEntity* QueryBoundedEntity() const override;
	ZBoundedEntity* QueryBoundedEntity() override;
	float4 GetLocalCenter() const override;
	float4 GetLocalHalfSize() const override;
	virtual void UpdateBounds();

	ZBoundedEntity() = default;
	static void RegisterType();
	ZBoundedEntity(const ZBoundedEntity& __that);
	ZBoundedEntity(ZComponentCreateInfo& info);
	const SVector3& GetLocalCenterInMem() const;
	const SVector3& GetLocalHalfSizeInMem() const;
	ZBoundedEntity& operator=(const ZBoundedEntity& __that);
};
