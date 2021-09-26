#pragma once

#include "ZMaterialDescriptorEntity.h"
#include "TSharedPointer.h"
#include "SComponentMapEntry.h"
#include "SVector2.h"
#include "TEntityRef.h"
#include "TResourcePtr.h"
#include "ZEntityRef.h"
#include "ZVariantRef.h"
#include "float4.h"

class IDecalControllerEntity;
class IEntityFactory;
class ZComponentCreateInfo;
class ZEntitySingleton;
class ZRenderMaterialInstance;
struct STypeID;

class ZHM5MaterialDescriptorEntity : public ZMaterialDescriptorEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TResourcePtr<IEntityFactory> m_pBulletDecalControllerFactory;
	TResourcePtr<ZRenderMaterialInstance> m_pBulletDecalMaterial;
	unsigned int m_nBulletDecalNumVariationsX;
	unsigned int m_nBulletDecalNumVariationsY;
	SVector2 m_vBulletDecalSize;
	float m_fBulletDecalSizeVariation;
	TResourcePtr<IEntityFactory> m_pSplatDecalControllerFactory;
	TResourcePtr<IEntityFactory> m_pSecondarySplatDecalControllerFactory;
	TResourcePtr<ZRenderMaterialInstance> m_pSplatDecalMaterial;
	unsigned int m_nSplatDecalNumVariationsX;
	unsigned int m_nSplatDecalNumVariationsY;
	SVector2 m_vSplatDecalSize;
	float m_fSplatDecalSizeVariation;
	TResourcePtr<IEntityFactory> m_pBloodPoolDecalControllerFactory;
	TResourcePtr<IEntityFactory> m_pBulletImpactFactory;
	float m_fPenetratableBulletEnergyThreshold;
	TSharedPointer<ZEntitySingleton> m_pBloodPoolDecalController;
	TSharedPointer<ZEntitySingleton> m_pSplatDecalController;
	TSharedPointer<ZEntitySingleton> m_pSecondarySplatDecalController;
	TSharedPointer<ZEntitySingleton> m_pBulletDecalController;
	bool m_bAlwaysPenetrable;
	int m_nBulletImpactEntryIndex;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5MaterialDescriptorEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	void Init() override;

	ZHM5MaterialDescriptorEntity() = default;
	static void RegisterType();
	ZHM5MaterialDescriptorEntity(ZComponentCreateInfo& Info);
	TEntityRef<IDecalControllerEntity> GetBulletDecalController() const;
	const TResourcePtr<ZRenderMaterialInstance>& GetBulletDecalMaterial() const;
	float4 GetBulletDecalSize() const;
	float GetBulletDecalSizeVariation() const;
	float4 GetBulletDecalNumVariations() const;
	TEntityRef<IDecalControllerEntity> GetSplatDecalController() const;
	TEntityRef<IDecalControllerEntity> GetSecondarySplatDecalController() const;
	const TResourcePtr<ZRenderMaterialInstance>& GetSplatDecalMaterial() const;
	float4 GetSplatDecalSize() const;
	float GetSplatDecalSizeVariation() const;
	float4 GetSplatDecalNumVariations() const;
	TEntityRef<IDecalControllerEntity> GetBloodPoolDecalController() const;
	ZEntityRef GetBulletImpact();
	bool IsPenetratable() const;
	float GetPenetratableBulletEnergyThreshold() const;
	void OnBulletDecalMaterialChanged();
	void OnSplatDecalMaterialChanged();
	void OnBulletImpactFactoryChanged();
	void OnBulletDecalControllerFactoryChanged();
	void OnSplatDecalControllerFactoryChanged();
	void OnSecondarySplatDecalControllerFactoryChanged();
	void OnBloodPoolDecalControllerFactoryChanged();
};
