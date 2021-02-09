#pragma once

class alignas(4) SDialogInformation
{
public:
    unsigned int m_nFlanked;
    bool m_bAnyNPCFiring;
    bool m_bTargetHit;
    bool m_bWeaponReloading;
    bool m_bInCover;
    bool m_bEnteringCloset;
    bool m_bInCloset;
    bool m_bShooting;
    bool m_bCloseCombat;
    bool m_bWieldingCCWeapon;
    bool m_bDefensiveShout;
    bool m_bPlayCmbtLngLstRsp;
    bool m_bPlayCmbtCvrFirRsp;
    bool m_bHitmanDead;
};
