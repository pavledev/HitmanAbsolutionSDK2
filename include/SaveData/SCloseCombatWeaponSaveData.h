#pragma once

#include "STokenID.h"

struct SCloseCombatWeaponSaveData
{
	STokenID m_ID;
	int m_nImpactCount;

	SCloseCombatWeaponSaveData(const STokenID& id, int nImpactCount);
	SCloseCombatWeaponSaveData() = default;
	~SCloseCombatWeaponSaveData() = default;
};
