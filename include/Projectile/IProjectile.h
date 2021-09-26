#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"
#include "SMatrix.h"
#include "float4.h"

class __declspec(novtable) IProjectile : public IComponentInterface
{
public:
	~IProjectile() override = default;
	virtual float CalcDamageByProjectile(const float4& param1) = 0;
	virtual const ZEntityRef GetProjectileOwner() = 0;
	virtual SMatrix GetProjectileStartMatPos() = 0;
	virtual float4 GetTrajectoryDir() const = 0;
	virtual unsigned int GetProjectileId() const = 0;
	virtual float GetImpactForce() const = 0;
	virtual void SetImpactForce(float param1) = 0;
	virtual float GetRagdollImpactForce() const = 0;
	virtual void SetRagdollImpactForce(float param1) = 0;
	virtual float GetRagdollImpactUpKick() const = 0;
	virtual void SetRagdollImpactUpKick(float param1) = 0;
	virtual bool IsNPCProjectile() const = 0;

	static void RegisterType();
	IProjectile() = default;
};
