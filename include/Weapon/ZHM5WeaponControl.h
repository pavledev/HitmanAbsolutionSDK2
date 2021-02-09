#pragma once

#include "SWeaponControlFlags.h"
#include "sOTSAimFlags.h"
#include "sAimFlags.h"
#include "ZGameTime.h"
#include "ZMapPoly.h"
#include "eWeaponAutoReloadState.h"
#include "ZEntityRef.h"
#include "TEntityRef.h"
#include "ZHitman5.h"
#include "ZHM5WeaponControlInputRepeater.h"

class ZHM5WeaponControl
{
public:
    alignas(8) SWeaponControlFlags m_WeaponControlFlags;
    sOTSAimFlags m_OTSFlags;
    sAimFlags* m_AimFlagsRef;
    ZGameTime m_TriggerReleaseTime;
    ZGameTime m_PreciseAimStartHoldTime;
    bool m_bHapticsPlayed;
    bool m_bCompletedSignalPending;
    float m_fLastValidImpactFraction;
    float m_fPreciseAimPrct;
    bool m_bRightHandWeaponFire;
    ZMapPoly m_MapPoly;
    eWeaponAutoReloadState m_eAutoReloadState;
    bool m_bWaitForBlindFireBlend;
    bool m_bStartAimCalled;
    bool m_bFocusCrosshairAnimStarted;
    ZEntityRef m_rPrecisionTarget;
    float m_fPrecisionTargetDelay;
    TEntityRef<ZHitman5> m_pHitman;
    ZHM5WeaponControlInputRepeater* m_pShootRepeater;
    ZGameTime m_tTimeSinceLastShotFired;
    ZGameTime m_tLastAimReleased;
    float m_fLHIKWeight;
    bool m_bWaitForTriggerRelease;
    bool m_bProjectilePreciseShot;
    bool m_bUpdateWeaponFire;

    enum EPropAnimType : __int32
    {
        ePropAnim_1H = 0x0,
        ePropAnim_2H = 0x1,
        ePropAnim_NumTypes = 0x2
    };

    virtual ~ZHM5WeaponControl();
};
