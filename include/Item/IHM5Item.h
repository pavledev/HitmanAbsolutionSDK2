#pragma once

#include "IComponentInterface.h"
#include "ZItemFactoryEntity.h"
#include "eItemSize.h"
#include "eItemHands.h"
#include "eItemType.h"
#include "TEntityRef.h"
#include "ZGeomEntity.h"
#include "ZLinkedEntity.h"
#include "SCollisionInfo.h"
#include "ZDynamicFlashMovieResource.h"
#include "IPhysicsAccessor.h"
#include "ZContentKitEntity.h"

class IHM5Item : public IComponentInterface
{
public:
    virtual void OnFactoryContructed(TEntityRef<ZItemFactoryEntity>);
    virtual eItemSize GetItemSize();
    virtual eItemHands GetItemHands();
    virtual eItemHands GetItemHandsCoverAnimLayer();
    virtual eItemType GetItemType();
    virtual const ZString* GetItemName();
    virtual ZString* GetItemTypeName(ZString* result);
    virtual bool IsInventoryItem();
    virtual bool IsInspectItem();
    virtual void OnAttachItem(const ZEntityRef*);
    virtual void OnReleaseItem(bool);
    virtual void OnThrowItem(const float4*, const float4*);
    virtual void OnHolsterItem(const ZEntityRef*);
    virtual void EnablePickup(bool);
    virtual void ShowItem(bool);
    virtual bool ItemHidden();
    virtual TEntityRef<ZSpatialEntity>* GetSpatialEntity(TEntityRef<ZSpatialEntity>* result);
    virtual TEntityRef<ZGeomEntity>* GetGeomEntity(TEntityRef<ZGeomEntity>* result);
    virtual ZLinkedEntity* GetLinkedEntity();
    virtual ZPrimitiveContainerEntity* GetPrimitiveContainerEntity();
    virtual const ZEntityRef* GetOwner();
    virtual void SetOwner(ZEntityRef);
    virtual void RemoveItemFromPhysicsWorld();
    virtual ZString* GetDebugName(ZString* result);
    virtual void Reset();
    virtual TEntityRef<ZSpatialEntity>* GetHandAttacher(TEntityRef<ZSpatialEntity>* result);
    virtual SMatrix* GetHandAttacherOffset(SMatrix* result);
    virtual void SetAIPerceptable(bool);
    virtual void SetThrown();
    virtual bool IsThrown();
    virtual void OnCollision(const SCollisionInfo*, bool);
    virtual SMatrix* GetMirroredGround(SMatrix* result);
    virtual bool IsPercievedAsWeapon();
    virtual bool CanBeDualWielded();
    virtual TResourcePtr<ZDynamicFlashMovieResource>* GetHUDIcon(TResourcePtr<ZDynamicFlashMovieResource>* result);
    virtual TResourcePtr<ZDynamicFlashMovieResource>* GetHUDSilencerIcon(TResourcePtr<ZDynamicFlashMovieResource>* result);
    virtual const SVector2* GetSilencerPos();
    virtual TEntityRef<IPhysicsAccessor>* GetPhysicsAccessor(TEntityRef<IPhysicsAccessor>* result);
    virtual void SetFactoryResource(const TResourcePtr<IHM5Item>*);
    virtual const STokenID* GetTokenID();
    virtual TEntityRef<ZContentKitEntity>* GetContentKitEntity(TEntityRef<ZContentKitEntity>* result);
    virtual void ContentKitEntityRetrieved();
    virtual ZEntityRef* GetItemEntity(ZEntityRef* result);
};
