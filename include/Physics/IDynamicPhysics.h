#pragma once

#include "IPhysicsAccessor.h"

class IDynamicPhysics : public IPhysicsAccessor
{
public:
    virtual TEntityRef<ZSpatialEntity>* GetSpatialOwner(TEntityRef<ZSpatialEntity>* result);
    virtual bool IsPhysicsObject();
    virtual IPhysicsObject* GetPhysicsObject();
    virtual bool IsRegisteredForPhysicsObjectListening(const ZDelegate<void __cdecl(IPhysicsAccessor const*, IPhysicsObject const*, IPhysicsObject const*)>*);
    virtual void RegisterForPhysicsObjectListening(const ZDelegate<void __cdecl(IPhysicsAccessor const*, IPhysicsObject const*, IPhysicsObject const*)>*);
    virtual void UnregisterForPhysicsObjectListening(const ZDelegate<void __cdecl(IPhysicsAccessor const*, IPhysicsObject const*, IPhysicsObject const*)>*);
    virtual void SetKinematic(bool);
    virtual bool GetKinematic();
    virtual void SetInPhysicsWorld(bool);
    virtual void ApplyImpulse(const float4*);
    virtual void ApplyTorque(const float4*);
    virtual void ApplyPointImpulse(const float4*, const float4*);
    virtual void UpdateSpatialTransformFromPhysicsObject();
};
