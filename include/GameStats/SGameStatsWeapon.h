#pragma once

#include "eItemType.h"
#include "STokenID.h"
#include "EWeaponSpecialSituation.h"
#include "eAmmoType.h"
#include "ZString.h"

struct SGameStatsWeapon
{
	eItemType m_eItemWeapon;
	STokenID m_WeaponTokenID;
	EWeaponSpecialSituation m_eSpecialSituation;
	eAmmoType m_eAmmoType;

	SGameStatsWeapon() = default;
	~SGameStatsWeapon() = default;
	bool IsFirearm() const;
	bool IsFiberWire() const;
	bool IsExplosion() const;
	bool IsAnyWeapon() const;
	bool IsProp() const;
	ZString GetWeaponName() const;
	bool operator==(const SGameStatsWeapon& other) const;
	bool operator!=(const SGameStatsWeapon& other) const;
};
