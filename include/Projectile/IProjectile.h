#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"
#include "SMatrix.h"
#include "float4.h"

class IProjectile : public IComponentInterface
{
public:
    virtual float CalcDamageByProjectile(const float4*);
    virtual const ZEntityRef* GetProjectileOwner(const ZEntityRef* result);
    virtual SMatrix* GetProjectileStartMatPos(SMatrix* result);
    virtual float4* GetTrajectoryDir(float4* result);
    virtual unsigned int GetProjectileId();
    virtual float GetImpactForce();
    virtual void SetImpactForce(float);
    virtual float GetRagdollImpactForce();
    virtual void SetRagdollImpactForce(float);
    virtual float GetRagdollImpactUpKick();
    virtual void SetRagdollImpactUpKick(float);
    virtual bool IsNPCProjectile();
};
