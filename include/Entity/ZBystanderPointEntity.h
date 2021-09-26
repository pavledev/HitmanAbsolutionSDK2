#pragma once

#include "ZSpatialEntity.h"
#include "EBystanderPointType.h"
#include "ZResourcePtr.h"
#include "SComponentMapEntry.h"
#include "TEntityRef.h"
#include "ZVariantRef.h"

class ZActor;
class ZComponentCreateInfo;
class ZString;
struct STypeID;

class ZBystanderPointEntity : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	EBystanderPointType m_eType;
	TEntityRef<ZActor> m_pPreferredActor;
	ZResourcePtr m_pGizmo;
	bool m_bHideOnStart;
	bool m_bPreferredActorIgnoreDanger;
	bool m_bEnabled;
	TEntityRef<ZActor> m_pReservedBy;

	static SComponentMapEntry s_componentMap[0];

	~ZBystanderPointEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;
	void Start() override;

	ZBystanderPointEntity() = default;
	static void RegisterType();
	ZBystanderPointEntity(ZComponentCreateInfo& info);
	void SetEnabled(bool bEnabled);
	bool IsReserved(TEntityRef<ZActor> pActor) const;
	void Reserve(TEntityRef<ZActor> pActor);
	void Unreserve(TEntityRef<ZActor> pActor);
	bool CanReserve(TEntityRef<ZActor> pActor) const;
	TEntityRef<ZActor> GetPreferredActor() const;
	bool GetPreferredActorIgnoreDanger() const;
	void OnGizmoChanged();
};
