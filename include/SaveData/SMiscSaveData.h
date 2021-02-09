#pragma once

#include "STokenID.h"

class SMiscSaveData
{
public:
    bool m_bCompletedFirstBoot;
    bool m_bContractsTutorialPlayShown;
    bool m_bContractsTutorialCreateShown;
    STokenID m_LastUnlockedOutfit;
    STokenID m_LastUnlockedWeapon;
    unsigned int m_iPOIProgressPointsWhenUnlockKeyMesageDisplayed;
};
