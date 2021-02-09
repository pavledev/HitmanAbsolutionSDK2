#pragma once

#include "ZEntityImpl.h"
#include "SGameUpdateEvent.h"

class ZHM5TutorialEventsEntity : public ZEntityImpl
{
public:
    bool m_bEnabled;
    __int8 m_bFired_AttentionGaugeActivated : 1;
    __int8 m_bFired_StartedTrespassing : 1;
    __int8 m_bFired_CoverActivated : 1;
    __int8 m_bFired_EnterWindowFromLedge : 1;
    __int8 m_bFired_CoverToCover : 1;
    __int8 m_bFired_CoverScale : 1;
    __int8 m_bFired_LedgeAgilityActivated : 1;
    __int8 m_bFired_CoverTakedownByPlayer : 1;
    __int8 m_bFired_ShootingBalletTag : 1;
    __int8 m_bFired_ShootingBalletExecute : 1;
    __int8 m_bFired_PullVictimPossible : 1;
    __int8 m_bTossAimToggle : 1;
    __int8 m_bFired_TossFire : 1;
    __int8 m_bFired_UsedFibreWire : 1;
    __int8 m_bFired_PickedUpCloseCombatProp : 1;
    __int8 m_bFired_SneakInputPressed : 1;
    __int8 m_bFired_RunInputPressed : 1;
    __int8 m_bFired_InstinctPressed : 1;
    __int8 m_bFired_InstinctReleased : 1;
    __int8 m_bCanExitCover : 1;
    __int8 m_bCanExitCoverOnlyForSBHack : 1;
    __int8 m_bFakeCloseCombatButtonPress : 1;
    __int8 m_bFakeCoverTakedownButtonPress : 1;
    __int8 m_bFakePushVictimButtonPress : 1;
    __int8 m_bLockLedgeMovementVer : 1;
    __int8 m_bLockLedgeMovementHor : 1;
    __int8 m_bIsGod : 1;
    __int8 m_bShowButtonsInSB : 1;
    __int8 m_bBurnInstinctInSB : 1;
    __int8 m_bBurnInstinctOnSBTag : 1;
    __int8 m_bCanExitSafeZone : 1;
    __int8 m_bActionOrientationActive : 1;
    __int8 m_bHairTrigger : 1;
    __int8 m_bCloseCombatSlowDownActivated : 1;
    __int8 m_bFired_LastWitnessKilled : 1;
    __int8 m_bLastWitnessKilled : 1;
    float m_fCurTimeMultiplier;
    float m_fDesiredTimeMultiplier;

    virtual void FrameUpdate(const SGameUpdateEvent*);
};
