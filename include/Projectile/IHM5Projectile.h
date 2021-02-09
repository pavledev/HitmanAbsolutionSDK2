#pragma once

#include "IProjectile.h"
#include "ZHM5ProjectileDamageProperties.h"
#include "ZHM5SBTag.h"

class IHM5Projectile : public IProjectile
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
    virtual bool IsActive();
    virtual void Activate(const ZHM5ProjectileDamageProperties*, const SMatrix43*, const float4*, bool, unsigned int, bool, bool);
    virtual eWeaponType GetWeaponType();
    virtual void SetSBTag(const ZHM5SBTag*);
    virtual eItemType GetItemType();
    virtual const STokenID* GetItemTypeToken();
    virtual eAmmoType GetAmmoType();
    virtual bool IsSBProjectile();
    virtual const ZHM5SBTag* GetSBTag();
};
