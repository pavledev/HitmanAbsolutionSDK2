#pragma once

#include "IComponentInterface.h"
#include "EConstraintType.h"
#include "float4.h"

class IPhysicsObject;

class __declspec(novtable) IBaseConstraint : public IComponentInterface
{
public:
	~IBaseConstraint() override = default;
	virtual EConstraintType GetConstraintType() const = 0;
	virtual void SetPhysicsObjects(IPhysicsObject* physicsObject, IPhysicsObject* physicsObject2) = 0;
	virtual IPhysicsObject* GetFirstObject() const = 0;
	virtual IPhysicsObject* GetSecondObject() const = 0;
	virtual void SetGlobalAnchor(const float4& param1) = 0;
	virtual void SetGlobalAxis(const float4& param1) = 0;
	virtual float4 GetGlobalAnchor() const = 0;
	virtual float4 GetGlobalAxis() const = 0;
	virtual void SetCollision(bool param1) = 0;
	virtual bool IsCollisionEnabled() const = 0;
	virtual void SetBreakableLimits(const float& param1, const float& param2) = 0;
	virtual float GetBreakableForce() const = 0;
	virtual float GetBreakableTorque() const = 0;
	virtual bool IsConstraintActive() const = 0;
	virtual bool IsConstraintBroken() const = 0;
	virtual bool IsConstraintInPhysicsWorld() const = 0;

	static void RegisterType();
	IBaseConstraint() = default;
};
