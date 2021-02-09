#pragma once

#include "IPhysicsObject.h"
#include "EPhysicsSystemType.h"
#include "TComponentSharedPtr.h"
#include "IBaseConstraint.h"
#include "TArrayRef.h"

class IPhysicsSystem
{
public:
    virtual ~IPhysicsSystem();
    virtual void Release();
    virtual bool ActivateSystem();
    virtual bool DeactivateSystem();
    virtual bool AddRigidBody(IPhysicsObject*);
    virtual bool RemoveRigidBody(unsigned int);
    virtual bool AddTargetDummy(IPhysicsObject*, IPhysicsObject*, bool);
    virtual bool RemoveTargetDummy(unsigned int);
    virtual unsigned int GetRigidBodyIndex(IPhysicsObject*);
    virtual const IPhysicsObject* GetRigidBodyConst(unsigned int); //original name is GetRigidBody
    virtual IPhysicsObject* GetRigidBody(unsigned int);
    virtual unsigned int GetRigidBodyAmount();
    virtual EPhysicsSystemType GetType();
    virtual IPhysicsObject* GetTargetDummyForRigidBody(IPhysicsObject*);
    virtual bool AddConstraint(TComponentSharedPtr<IBaseConstraint>);
    virtual void AddAllConstraintsToWorld();
    virtual bool RemoveConstraint(unsigned int);
    virtual void RemoveAllConstraints();
    virtual const TComponentSharedPtr<IBaseConstraint>* GetConstraint(const TComponentSharedPtr<IBaseConstraint>* result, unsigned int);
    virtual TComponentSharedPtr<IBaseConstraint>* GetConstraint(TComponentSharedPtr<IBaseConstraint>* result, unsigned int);
    virtual unsigned int GetConstraintAmount();
    virtual TArrayRef<IPhysicsObject*>* GetRigidBodies(TArrayRef<IPhysicsObject*>* result);
    virtual const TArrayRef<IPhysicsObject*>* GetRigidBodies(const TArrayRef<IPhysicsObject*>* result);
    virtual TArrayRef<IPhysicsObject*>* GetTargetDummies(TArrayRef<IPhysicsObject*>* result);
    virtual const TArrayRef<IPhysicsObject*>* GetTargetDummies(const TArrayRef<IPhysicsObject*>* result);
    virtual const TArrayRef<IBaseConstraint*>* GetTargetDummyConstraints(const TArrayRef<IBaseConstraint*>* result);
    virtual TArrayRef<IBaseConstraint*>* GetTargetDummyConstraints(TArrayRef<IBaseConstraint*>* result);
    virtual TArrayRef<TComponentSharedPtr<IBaseConstraint> >* GetConstraints(TArrayRef<TComponentSharedPtr<IBaseConstraint> >* result);
    virtual const TArrayRef<TComponentSharedPtr<IBaseConstraint> >* GetConstraints(const TArrayRef<TComponentSharedPtr<IBaseConstraint> >* result);
    virtual void SetCollisionLayer(const unsigned __int16);
    virtual unsigned __int16 GetCollisionLayer();
    virtual void SetEntity(const ZEntityRef*);
    virtual ZEntityRef* GetEntity(ZEntityRef* result);
    virtual bool IsSystemInPhysicsWorld();
    virtual void SetAddedToPhysicsWorld();
    virtual void SetRemovedFromPhysicsWorld();
    virtual void PutToSleep();
    virtual void DisableWorldInteraction();
    virtual void RestoreWorldInteraction();
};
