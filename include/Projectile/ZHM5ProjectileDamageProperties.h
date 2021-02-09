#pragma once

#include "ZEntityRef.h"
#include "TEntityRef.h"
#include "IHM5ItemWeapon.h"

class alignas(16) ZHM5ProjectileDamageProperties
{
public:
    float m_fMuzzleVelocity;
    float m_fCloseRange;
    float m_fNearRange;
    float m_fMediumRange;
    float m_fFarRange;
    float m_fDamageMultiplier;
    float m_fMuzzleEnergyMultiplier;
    ZEntityRef m_rOwner;
    TEntityRef<IHM5ItemWeapon> m_rWeapon;
    IHM5AmmoProperties* m_pAmmoProperties;
    eWeaponType m_eWeaponType;
    eItemType m_eItemType;
    EHM5SoundBulletType m_eSoundBulletType;
    float4 m_vMuzzleExitPos;
    float4 m_vTracerStartPos;
    bool m_bTracerRound;
    STokenID m_ItemTypeToken;
};
