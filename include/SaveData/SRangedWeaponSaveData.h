#pragma once

#include "STokenID.h"
#include "TArray.h"

class SRangedWeaponSaveData
{
public:
    STokenID m_ID;
    int m_nBulletsInMagazine;
    bool m_bAltFire;
    TArray<bool> m_aUpgradesState;
};
