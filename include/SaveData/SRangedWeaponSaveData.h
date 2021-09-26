#pragma once

#include "STokenID.h"
#include "TArray.h"

struct SRangedWeaponSaveData
{
	STokenID m_ID;
	int m_nBulletsInMagazine;
	bool m_bAltFire;
	TArray<bool> m_aUpgradesState;

	SRangedWeaponSaveData(const SRangedWeaponSaveData& __that);
	SRangedWeaponSaveData(const STokenID& id, int nBulletsInMagazine, bool bAltFire, TArray<bool> aUpgradesState);
	SRangedWeaponSaveData() = default;
	~SRangedWeaponSaveData() = default;
	SRangedWeaponSaveData& operator=(const SRangedWeaponSaveData& __that);
};
