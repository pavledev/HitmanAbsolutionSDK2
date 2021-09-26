#pragma once

#include "ZBoundedEntity.h"
#include "IFabricColliderEntity.h"
#include "EFabricColliderTypes.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZVariantRef.h"

class IFabricEntity;
class ZComponentCreateInfo;
class ZString;
struct STypeID;
template <class T> class TEntityRef;

class ZFabricColliderBaseEntity : public ZBoundedEntity, public IFabricColliderEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bEnabled;
	bool m_bGlobal;
	TArray<TEntityRef<IFabricEntity>> m_FabricEntities;
	bool m_bActivated : 1;
	EFabricColliderTypes m_type : 3;

	static SComponentMapEntry s_componentMap[0];

	~ZFabricColliderBaseEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	ZFabricColliderBaseEntity() = default;
	static void RegisterType();
	ZFabricColliderBaseEntity(ZComponentCreateInfo& Info);
	void MoreFabricEntities(TArray<TEntityRef<IFabricEntity>>& newFabricEntities);
	void LessFabricEntities(TArray<TEntityRef<IFabricEntity>>& oldFabricEntities);
	void OnShapeChanged();
	void OnEnable();
	void OnDisable();
	void OnEnabledChanged(const bool& bOldEnabled);
	void RegisterWithManager();
	void UnregisterWithManager();
};
