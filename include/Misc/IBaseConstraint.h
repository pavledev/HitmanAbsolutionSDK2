#pragma once

#include "IComponentInterface.h"
#include "EConstraintType.h"
#include "IPhysicsObject.h"

class IBaseConstraint : public IComponentInterface
{
public:
    virtual EConstraintType GetConstraintType();
    virtual void SetPhysicsObjects(IPhysicsObject*, IPhysicsObject*);
    virtual IPhysicsObject* GetFirstObject();
    virtual IPhysicsObject* GetSecondObject();
    virtual void SetGlobalAnchor(const float4*);
    virtual void SetGlobalAxis(const float4*);
    virtual float4* GetGlobalAnchor(float4* result);
    virtual float4* GetGlobalAxis(float4* result);
    virtual void SetCollision(bool);
    virtual bool IsCollisionEnabled();
    virtual void SetBreakableLimits(const float*, const float*);
    virtual float GetBreakableForce();
    virtual float GetBreakableTorque();
    virtual bool IsConstraintActive();
    virtual bool IsConstraintBroken();
    virtual bool IsConstraintInPhysicsWorld();
};
