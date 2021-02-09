#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZHM5WeaponUpgradeEntity.h"

class ZHM5WeaponBasicConfigEntity : public ZEntityImpl
{
public:
    TArray<TEntityRef<ZHM5WeaponUpgradeEntity>> m_Upgrades;
    bool m_bUpgradesVisibleInMenu;
    int m_iUnlockPriceSlot1;
    int m_iUnlockPriceSlot2;
    int m_iUnlockPriceSlot3;
    float m_fStatsRange;
    float m_fStatsDamage;
    float m_fStatsAccuracy;
    float m_fStatsFireRate;
    float m_fDamageClose;
    float m_fDamageNear;
    float m_fDamageMedium;
    float m_fDamageFar;
    float m_fDamageMultiplier;
    float m_fRangeClose;
    float m_fRangeNear;
    float m_fRangeMedium;
    float m_fRangeFar;
    int m_iBulletsPerMagazine;
    float m_fInitialMagazines;
    int m_iShotsPerMinute;
    float m_fReloadFactor;
    int m_iPrecisionNumBullets;
    float m_fPrecisionMinDegree;
    float m_fPrecisionMaxDegree;
    float m_fRecoilX;
    float m_fRecoilZ;
};
