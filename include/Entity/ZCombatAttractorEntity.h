#pragma once

#include "ZSpatialEntity.h"
#include "ZResourcePtr.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZString;
struct STypeID;
struct float4;

class ZCombatAttractorEntity : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZResourcePtr m_pGizmo;
	bool m_bActivateOnStart;
	float m_fRange;
	bool m_bIsActive;

	static SComponentMapEntry s_componentMap[0];

	~ZCombatAttractorEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	ZCombatAttractorEntity() = default;
	static void RegisterType();
	ZCombatAttractorEntity(ZComponentCreateInfo& info);
	bool IsInside(const float4& vPosition);
	void OnRegister();
	void OnUnregister();
	void OnGizmoChanged();
};
