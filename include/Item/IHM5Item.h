#pragma once

#include "IComponentInterface.h"
#include "eItemSize.h"
#include "eItemHands.h"
#include "eItemType.h"
#include "TEntityRef.h"
#include "SMatrix.h"
#include "TResourcePtr.h"
#include "ZEntityRef.h"
#include "ZString.h"

struct SVector2;
class IPhysicsAccessor;
class ZContentKitEntity;
class ZDynamicFlashMovieResource;
class ZGeomEntity;
class ZItemFactoryEntity;
class ZLinkedEntity;
class ZPrimitiveContainerEntity;
class ZSpatialEntity;
struct SCollisionInfo;
struct STokenID;
struct float4;

class __declspec(novtable) IHM5Item : public IComponentInterface
{
public:
	~IHM5Item() override = default;
	virtual void OnFactoryContructed(TEntityRef<ZItemFactoryEntity> entityRef) = 0;
	virtual eItemSize GetItemSize() const = 0;
	virtual eItemHands GetItemHands() const = 0;
	virtual eItemHands GetItemHandsCoverAnimLayer() const = 0;
	virtual eItemType GetItemType() const = 0;
	virtual const ZString& GetItemName() const = 0;
	virtual ZString GetItemTypeName() const = 0;
	virtual bool IsInventoryItem() const = 0;
	virtual bool IsInspectItem() const = 0;
	virtual void OnAttachItem(const ZEntityRef& entityRef) = 0;
	virtual void OnReleaseItem(bool param1) = 0;
	virtual void OnThrowItem(const float4& param1, const float4& param2) = 0;
	virtual void OnHolsterItem(const ZEntityRef& entityRef) = 0;
	virtual void EnablePickup(bool param1) = 0;
	virtual void ShowItem(bool param1) = 0;
	virtual bool ItemHidden() const = 0;
	virtual TEntityRef<ZSpatialEntity> GetSpatialEntity() const = 0;
	virtual TEntityRef<ZGeomEntity> GetGeomEntity() const = 0;
	virtual ZLinkedEntity* GetLinkedEntity() const = 0;
	virtual ZPrimitiveContainerEntity* GetPrimitiveContainerEntity() const = 0;
	virtual const ZEntityRef& GetOwner() const = 0;
	virtual void SetOwner(ZEntityRef entityRef) = 0;
	virtual void RemoveItemFromPhysicsWorld() = 0;
	virtual ZString GetDebugName() const = 0;
	virtual void Reset() = 0;
	virtual TEntityRef<ZSpatialEntity> GetHandAttacher() const = 0;
	virtual SMatrix GetHandAttacherOffset() const = 0;
	virtual void SetAIPerceptable(bool param1) = 0;
	virtual void SetThrown() = 0;
	virtual bool IsThrown() const = 0;
	virtual void OnCollision(const SCollisionInfo& collisionInfo, bool param2) = 0;
	virtual SMatrix GetMirroredGround() const = 0;
	virtual bool IsPercievedAsWeapon() const = 0;
	virtual bool CanBeDualWielded() const = 0;
	virtual TResourcePtr<ZDynamicFlashMovieResource> GetHUDIcon() const = 0;
	virtual TResourcePtr<ZDynamicFlashMovieResource> GetHUDSilencerIcon() const = 0;
	virtual const SVector2& GetSilencerPos() const = 0;
	virtual TEntityRef<IPhysicsAccessor> GetPhysicsAccessor() const = 0;
	virtual void SetFactoryResource(const TResourcePtr<IHM5Item>& resourcePtr) = 0;
	virtual const STokenID& GetTokenID() const = 0;
	virtual TEntityRef<ZContentKitEntity> GetContentKitEntity() const = 0;
	virtual void ContentKitEntityRetrieved() = 0;
	virtual ZEntityRef GetItemEntity() const = 0;

	static void RegisterType();
	IHM5Item() = default;
};
