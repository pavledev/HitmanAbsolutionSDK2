#pragma once

#include "IComponentInterface.h"
#include "eAmmoType.h"
#include "ZEntityRef.h"
#include "ZString.h"

class __declspec(novtable) IHM5AmmoProperties : public IComponentInterface
{
public:
	~IHM5AmmoProperties() override = default;
	virtual int GetProjectilesPerShot() const = 0;
	virtual bool IsArmorPiercing() const = 0;
	virtual eAmmoType GetAmmoType() const = 0;
	virtual ZString GetLocalizedName() const = 0;
	virtual float GetBlodSplatSizeMultiplier() const = 0;
	virtual int GetBloodSplatTypeIndex() const = 0;
	virtual float GetMuzzleEnergy() const = 0;
	virtual ZEntityRef GetTracerEffect() const = 0;
	virtual int GetTracerEveryNthBullet() const = 0;
	virtual int GetBulletsPerMagazine() const = 0;
	virtual int GetInitialBullets() const = 0;
	virtual float GetCloseDamage() const = 0;
	virtual float GetNearDamage() const = 0;
	virtual float GetMediumDamage() const = 0;
	virtual float GetFarDamage() const = 0;

	static void RegisterType();
	IHM5AmmoProperties() = default;
};
