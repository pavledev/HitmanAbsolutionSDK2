#pragma once

#include "IComponentInterface.h"
#include "SHitInfo.h"
#include "TEntityRef.h"
#include "ZSpatialEntity.h"

class IBaseCharacter : public IComponentInterface
{
public:
    virtual void YouGotHit(const SHitInfo*);
    virtual bool CanProjectileHitCharacter(const SHitInfo*);
    virtual unsigned __int16 GetCollisionLayer();
    virtual bool RegisterAttachment(unsigned int, TEntityRef<ZSpatialEntity>);
    virtual void UnregisterAttachment(unsigned int, TEntityRef<ZSpatialEntity>);
    virtual bool IsRagdoll();
    virtual ZEntityRef* GetLinkedEntityBase(ZEntityRef* result);

    IBaseCharacter();
    IBaseCharacter(IBaseCharacter const&);
    IBaseCharacter* operator=(IBaseCharacter const&);
};
