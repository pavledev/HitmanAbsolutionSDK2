#pragma once

#include "IComponentInterface.h"
#include "eAmmoType.h"
#include "ZEntityRef.h"

class IHM5AmmoProperties : public IComponentInterface
{
public:
    virtual int GetProjectilesPerShot();
    virtual bool IsArmorPiercing();
    virtual eAmmoType GetAmmoType();
    virtual ZString* GetLocalizedName(ZString* result);
    virtual float GetBlodSplatSizeMultiplier();
    virtual int GetBloodSplatTypeIndex();
    virtual float GetMuzzleEnergy();
    virtual ZEntityRef* GetTracerEffect(ZEntityRef* result);
    virtual int GetTracerEveryNthBullet();
    virtual int GetBulletsPerMagazine();
    virtual int GetInitialBullets();
    virtual float GetCloseDamage();
    virtual float GetNearDamage();
    virtual float GetMediumDamage();
    virtual float GetFarDamage();
};
