#pragma once

#include "ZReusablePropEntity.h"
#include "IHM5Item.h"
#include "IAnimPlayerEntity.h"
#include "ZHM5Action.h"
#include "ZSharedKnowledgeRef.h"
#include "SVector2.h"
#include "STokenID.h"

class IPhysicsObject;
struct SGameUpdateEvent;

class ZHM5Item : public ZReusablePropEntity, public IHM5Item
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	eItemSize m_ItemSize;
	eItemHands m_ItemHands;
	eItemHands m_ItemHandsCoverAnimLayer;
	eItemType m_ItemType;
	ZEntityRef m_rPickupAction;
	TEntityRef<ZSpatialEntity> m_rGeomentity;
	TEntityRef<IPhysicsAccessor> m_rPhysicsAccessor;
	TEntityRef<ZSpatialEntity> m_PosHandAttach;
	TEntityRef<IAnimPlayerEntity> m_AnimPlayer;
	TResourcePtr<ZDynamicFlashMovieResource> m_pHUDIcon;
	TResourcePtr<ZDynamicFlashMovieResource> m_pHUDSilencerIcon;
	SVector2 m_vSilencerPos;
	bool m_bFixed;
	bool m_bEnablePickupInContracts;
	ZResourcePtr m_pFactoryResourcePtr;
	TResourcePtr<ZEntityRef> m_ContentKitEntity;
	STokenID m_TokenId;
	TEntityRef<ZGeomEntity> m_pGeomEntity;
	ZLinkedEntity* m_pGeomLinkedEntityInterface;
	ZPrimitiveContainerEntity* m_pPrimitiveContainerInterface;
	ZHM5Action* m_pPickupActionInterface;
	ZEntityRef m_pOwner;
	SMatrix m_MirroredGround;
	bool m_bEnablePickup : 1;
	bool m_bVisible : 1;
	bool m_bObjectInPhysicsWorld : 1;
	bool m_bThrown : 1;
	bool m_bActivated : 1;
	bool m_bRegisteredTriggerEntity : 1;
	ZSharedKnowledgeRef m_rAIObject;
	ZString m_sItemName;
	TEntityRef<ZItemFactoryEntity> m_pFactoryEntity;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snOwnedByHitman;
	static unsigned int m_snOwnedByNPC;
	static unsigned int m_snAddedToPhysicsWorld;
	static unsigned int m_snOnVisible;
	static unsigned int m_snOnInvisible;
	static unsigned int m_snEnablePickup;
	static unsigned int m_snOnHolster;
	static unsigned int m_snOnAttach;
	static unsigned int m_snOnRelease;

	~ZHM5Item() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;
	virtual const ZResourcePtr& GetFactoryResource() const;
	virtual void ResourceChanged();
	virtual void OnThrowImpact(const SCollisionInfo& collInfo);
	virtual void CheckFireOwnershipPins();
	virtual unsigned short GetCollisionLayer() const;

	void OnFactoryContructed(TEntityRef<ZItemFactoryEntity> pFactoryEntity) override;
	eItemSize GetItemSize() const override;
	eItemHands GetItemHands() const override;
	eItemHands GetItemHandsCoverAnimLayer() const override;
	eItemType GetItemType() const override;
	const ZString& GetItemName() const override;
	ZString GetItemTypeName() const override;
	bool IsInventoryItem() const override;
	bool IsInspectItem() const override;
	void OnAttachItem(const ZEntityRef& pOwner) override;
	void OnReleaseItem(bool bAddToPhysicsWorld) override;
	void OnThrowItem(const float4& vVelocity, const float4& vPos) override;
	void OnHolsterItem(const ZEntityRef& pOwner) override;
	void EnablePickup(bool bEnable) override;
	void ShowItem(bool bShow) override;
	bool ItemHidden() const override;
	TEntityRef<ZSpatialEntity> GetSpatialEntity() const override;
	TEntityRef<ZGeomEntity> GetGeomEntity() const override;
	ZLinkedEntity* GetLinkedEntity() const override;
	ZPrimitiveContainerEntity* GetPrimitiveContainerEntity() const override;
	const ZEntityRef& GetOwner() const override;
	void SetOwner(ZEntityRef pOwner) override;
	void RemoveItemFromPhysicsWorld() override;
	ZString GetDebugName() const override;
	void Reset() override;
	TEntityRef<ZSpatialEntity> GetHandAttacher() const override;
	SMatrix GetHandAttacherOffset() const override;
	void SetAIPerceptable(bool bPerceptable) override;
	void SetThrown() override;
	bool IsThrown() const override;
	void OnCollision(const SCollisionInfo& collInfo, bool bIsItemCollider) override;
	SMatrix GetMirroredGround() const override;
	bool IsPercievedAsWeapon() const override;
	bool CanBeDualWielded() const override;
	TResourcePtr<ZDynamicFlashMovieResource> GetHUDIcon() const override;
	TResourcePtr<ZDynamicFlashMovieResource> GetHUDSilencerIcon() const override;
	const SVector2& GetSilencerPos() const override;
	TEntityRef<IPhysicsAccessor> GetPhysicsAccessor() const override;
	void SetFactoryResource(const TResourcePtr<IHM5Item>& pFactoryResourcePtr) override;
	const STokenID& GetTokenID() const override;
	TEntityRef<ZContentKitEntity> GetContentKitEntity() const override;
	void ContentKitEntityRetrieved() override;
	ZEntityRef GetItemEntity() const override;

	ZHM5Item() = default;
	static void RegisterType();
	ZHM5Item(ZComponentCreateInfo& pInfo);
	void OnEnablePickupItem();
	void OnDisablePickupItem();
	void OnEnableAIPerceptible();
	void OnDisableAIPerceptible();
	bool IsActivated() const;
	bool IsPickupEnabled() const;
	ZSharedKnowledgeRef GetAIObject() const;
	bool IsAIPerceptable() const;
	void SetKinematic(bool bKinematic);
	void PhysicsObjectCallback(const IPhysicsAccessor* pPhysicsAccessor, const IPhysicsObject* pOldPhysicsObject, const IPhysicsObject* pNewPhysicsObject);
	void CalcMirrorGround();
	void OnSilencerPosChanged();
	void ThrownTriggerStart();
	void ThrownTriggerUpdate(const SGameUpdateEvent& updateEvent);
	void ThrownTriggerEnd();
	void AddRemoveItemFromPhysicsWorld(bool bAdd);
	void OnContentKitEntityChanged();
	TEntityRef<IAnimPlayerEntity> GetAnimPlayerEntity() const;
};
