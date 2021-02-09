#pragma once

#include "IComponentInterface.h"
#include "TEntityRef.h"
#include "ZSpatialEntity.h"
#include "IPhysicsObject.h"

class IPhysicsAccessor : public IComponentInterface
{
public:
    virtual TEntityRef<ZSpatialEntity>* GetSpatialOwner(TEntityRef<ZSpatialEntity>* result);
    virtual bool IsPhysicsObject();
    virtual IPhysicsObject* GetPhysicsObject();
    virtual bool IsRegisteredForPhysicsObjectListening(const ZDelegate<void __cdecl(IPhysicsAccessor const*, IPhysicsObject const*, IPhysicsObject const*)>*);
    virtual void RegisterForPhysicsObjectListening(const ZDelegate<void __cdecl(IPhysicsAccessor const*, IPhysicsObject const*, IPhysicsObject const*)>*);
    virtual void UnregisterForPhysicsObjectListening(const ZDelegate<void __cdecl(IPhysicsAccessor const*, IPhysicsObject const*, IPhysicsObject const*)>*);
};
