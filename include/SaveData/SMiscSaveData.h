#pragma once

#include "STokenID.h"

struct SMiscSaveData
{
	bool m_bCompletedFirstBoot;
	bool m_bContractsTutorialPlayShown;
	bool m_bContractsTutorialCreateShown;
	STokenID m_LastUnlockedOutfit;
	STokenID m_LastUnlockedWeapon;
	unsigned int m_iPOIProgressPointsWhenUnlockKeyMesageDisplayed;

	SMiscSaveData() = default;
	~SMiscSaveData() = default;
};
