#pragma once

#include "ZSpatialEntity.h"
#include "TResourcePtr.h"
#include "SComponentMapEntry.h"
#include "TEntityRef.h"
#include "ZRuntimeResourceID.h"
#include "ZVariantRef.h"

class IEntityFactory;
class IHM5Outfit;
class ZComponentCreateInfo;
class ZString;
struct STypeID;

class ZHM5ClothBundleEntity : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TResourcePtr<IEntityFactory> m_pClothBundleSpatialEntityFactory;
	ZRuntimeResourceID m_ridClothBundleSpatialEntity;
	TEntityRef<IHM5Outfit> m_pOutfitReference;
	ZRuntimeResourceID m_ridDisguisePrimResource;
	float m_fButtonHeightOffset;
	TEntityRef<ZSpatialEntity> m_editModeEntity;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snPickedUp;
	static unsigned int m_snPickupDone;

	~ZHM5ClothBundleEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void OnEnterEditMode() override;
	void OnExitEditMode() override;

	ZHM5ClothBundleEntity() = default;
	static void RegisterType();
	ZHM5ClothBundleEntity(ZComponentCreateInfo& info);
	void PickedUp();
	void PickupDone();
	float GetButtonHeightOffset() const;
};
