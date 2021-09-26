#pragma once

#include "IProjectile.h"
#include "ZHM5ProjectileDamageProperties.h"
#include "ZHM5SBTag.h"
#include "eAmmoType.h"

class __declspec(novtable) IHM5Projectile : public IProjectile
{
public:
	~IHM5Projectile() override = default;
	virtual bool IsActive() = 0;
	virtual void Activate(const ZHM5ProjectileDamageProperties& projectileDamageProperties, const SMatrix43& matrix43, const float4& param3, bool param4, unsigned int param5, bool param6, bool param7) = 0;
	virtual eWeaponType GetWeaponType() const = 0;
	virtual void SetSBTag(const ZHM5SBTag* tag) = 0;
	virtual eItemType GetItemType() const = 0;
	virtual const STokenID& GetItemTypeToken() const = 0;
	virtual eAmmoType GetAmmoType() const = 0;
	virtual bool IsSBProjectile() const = 0;
	virtual const ZHM5SBTag* GetSBTag() const = 0;

	static void RegisterType();
	IHM5Projectile() = default;
};
