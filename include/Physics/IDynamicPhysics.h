#pragma once

#include "IPhysicsAccessor.h"

struct float4;

class __declspec(novtable) IDynamicPhysics : public IPhysicsAccessor
{
public:
	~IDynamicPhysics() override = default;
	virtual void SetKinematic(bool param1) = 0;
	virtual bool GetKinematic() const = 0;
	virtual void SetInPhysicsWorld(bool param1) = 0;
	virtual void ApplyImpulse(const float4& param1) = 0;
	virtual void ApplyTorque(const float4& param1) = 0;
	virtual void ApplyPointImpulse(const float4& param1, const float4& param2) = 0;
	virtual void UpdateSpatialTransformFromPhysicsObject() = 0;

	static void RegisterType();
	IDynamicPhysics() = default;
};
