#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "TResourcePtr.h"
#include "ZTextListData.h"
#include "EWeaponUpgradeIcon.h"
#include "EWeaponUpgradeUse.h"

class alignas(4) ZHM5WeaponUpgradeEntity : public ZEntityImpl
{
public:
    TEntityRef<ZHM5WeaponUpgradeEntity> m_NextLevel;
    ZString m_TitleLoganID;
    ZString m_DescriptionLoganID;
    TResourcePtr<ZTextListData> m_pTextListResource;
    EWeaponUpgradeIcon m_eMenuIcon;
    int m_iUnlockPrice;
    int m_iPOICost;
    float m_fStatsRangeDelta;
    float m_fStatsDamageDelta;
    float m_fStatsAccuracyDelta;
    float m_fStatsFireRateDelta;
    bool m_bStartsActive;
    alignas(4) EWeaponUpgradeUse m_eWeaponUpgradeUse;
    bool m_bStartsDual;
    alignas(4) float m_fDamageCloseBonus;
    float m_fDamageNearBonus;
    float m_fDamageMediumBonus;
    float m_fDamageFarBonus;
    float m_fDamageMultiplierBonus;
    float m_fRangeCloseBonus;
    float m_fRangeNearBonus;
    float m_fRangeMediumBonus;
    float m_fRangeFarBonus;
    int m_iBulletsPerMagazineBonus;
    float m_fInitialMagazinesBonus;
    float m_fShotsPerMinuteBonus;
    float m_fReloadSpeedFactorBonus;
    float m_fRecoilXPenalty;
    float m_fRecoilZPenalty;
    int m_iPrecisionNumBonus;
    float m_fPrecisionMinDegreePenalty;
    float m_fPrecisionMaxDegreePenalty;
    bool m_bMakeSilenced;
    bool m_bMakeRedDot;
    bool m_bShowBoneA;
    alignas(4) ZString m_BoneNameA;
    bool m_bShowBoneB;
    alignas(4) ZString m_BoneNameB;
};
