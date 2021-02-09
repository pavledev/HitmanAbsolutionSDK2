#pragma once

#include "ZReusablePropEntity.h"
#include "IHM5Item.h"
#include "IAnimPlayerEntity.h"
#include "ZHM5Action.h"
#include "ZSharedKnowledgeRef.h"

class alignas(16) ZHM5Item : public ZReusablePropEntity, public IHM5Item
{
public:
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
    __int8 m_bEnablePickup : 1;
    __int8 m_bVisible : 1;
    __int8 m_bObjectInPhysicsWorld : 1;
    __int8 m_bThrown : 1;
    __int8 m_bActivated : 1;
    __int8 m_bRegisteredTriggerEntity : 1;
    ZSharedKnowledgeRef m_rAIObject;
    ZString m_sItemName;
    TEntityRef<ZItemFactoryEntity> m_pFactoryEntity;

    virtual const ZResourcePtr* GetFactoryResource();
    virtual void ResourceChanged();
    virtual void OnThrowImpact(const SCollisionInfo*);
    virtual void CheckFireOwnershipPins();
    virtual unsigned __int16 GetCollisionLayer();
};
