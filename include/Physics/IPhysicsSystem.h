#pragma once

#include "EPhysicsSystemType.h"
#include "TComponentSharedPtr.h"
#include "TArrayRef.h"
#include "ZEntityRef.h"

class IBaseConstraint;
class IPhysicsObject;

class __declspec(novtable) IPhysicsSystem
{
public:
	virtual ~IPhysicsSystem() = default;
	virtual void Release() = 0;
	virtual bool ActivateSystem() = 0;
	virtual bool DeactivateSystem() = 0;
	virtual bool AddRigidBody(IPhysicsObject* physicsObject) = 0;
	virtual bool RemoveRigidBody(unsigned int param1) = 0;
	virtual bool AddTargetDummy(IPhysicsObject* physicsObject, IPhysicsObject* physicsObject2, bool param3) = 0;
	virtual bool RemoveTargetDummy(unsigned int param1) = 0;
	virtual unsigned int GetRigidBodyIndex(IPhysicsObject* physicsObject) const = 0;
	virtual const IPhysicsObject* GetRigidBody(unsigned int param1) const = 0;
	virtual IPhysicsObject* GetRigidBody(unsigned int param1) = 0;
	virtual unsigned int GetRigidBodyAmount() const = 0;
	virtual EPhysicsSystemType GetType() const = 0;
	virtual IPhysicsObject* GetTargetDummyForRigidBody(IPhysicsObject* physicsObject) const = 0;
	virtual bool AddConstraint(TComponentSharedPtr<IBaseConstraint> componentSharedPtr) = 0;
	virtual void AddAllConstraintsToWorld() = 0;
	virtual bool RemoveConstraint(unsigned int param1) = 0;
	virtual void RemoveAllConstraints() = 0;
	virtual const TComponentSharedPtr<IBaseConstraint> GetConstraint(unsigned int param1) const = 0;
	virtual TComponentSharedPtr<IBaseConstraint> GetConstraint(unsigned int param1) = 0;
	virtual unsigned int GetConstraintAmount() const = 0;
	virtual TArrayRef<IPhysicsObject*> GetRigidBodies() = 0;
	virtual const TArrayRef<IPhysicsObject*> GetRigidBodies() const = 0;
	virtual TArrayRef<IPhysicsObject*> GetTargetDummies() = 0;
	virtual const TArrayRef<IPhysicsObject*> GetTargetDummies() const = 0;
	virtual const TArrayRef<IBaseConstraint*> GetTargetDummyConstraints() const = 0;
	virtual TArrayRef<IBaseConstraint*> GetTargetDummyConstraints() = 0;
	virtual TArrayRef<TComponentSharedPtr<IBaseConstraint>> GetConstraints() = 0;
	virtual const TArrayRef<TComponentSharedPtr<IBaseConstraint>> GetConstraints() const = 0;
	virtual void SetCollisionLayer(const unsigned short param1) = 0;
	virtual unsigned short GetCollisionLayer() const = 0;
	virtual void SetEntity(const ZEntityRef& entityRef) = 0;
	virtual ZEntityRef GetEntity() const = 0;
	virtual bool IsSystemInPhysicsWorld() const = 0;
	virtual void SetAddedToPhysicsWorld() = 0;
	virtual void SetRemovedFromPhysicsWorld() = 0;
	virtual void PutToSleep() = 0;
	virtual void DisableWorldInteraction() = 0;
	virtual void RestoreWorldInteraction() = 0;

	IPhysicsSystem() = default;
};
