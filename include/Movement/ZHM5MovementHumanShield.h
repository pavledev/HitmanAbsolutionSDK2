#pragma once

#include "ZHM5BaseMovement.h"
#include "ZActor.h"
#include "ECCLeeState.h"
#include "HM5Utils.h"
#include "ZInventorySlot.h"

class alignas(16) ZHM5MovementHumanShield : ZHM5BaseMovement
{
    TEntityRef<ZActor> m_rArrestActor;
    TEntityRef<ZActor> m_pHumanShieldVictim;
    TEntityRef<ZCrowdActor> m_pCrowdActorTarget;
    unsigned int m_nStrafeStateIDs[4];
    unsigned int m_nHumanShieldStateMachineID;
    unsigned int m_nHumanShieldEnterSM;
    unsigned int m_nEnterHSShieldGrabAnimNodeID;
    unsigned int m_nEnterHSDisarmRifleAnimNodeID;
    unsigned int m_nEnterHSDisarmGunAnimNodeID;
    unsigned int m_nExitHSAnimNodeID;
    unsigned int m_nExitKillHSAnimNodeID;
    unsigned int m_nFreeAttacherID;
    ECCLeeState m_eHumanShieldState;
    unsigned int m_nEnterAnimNodeID;
    unsigned int m_nExitAnimNodeID;
    bool m_bFromSurrender;
    SMatrix m_mvVictimStart;
    SMatrix m_aBlendMats[3];
    HM5Utils::SAnimBlend m_aAnimBlends[3];
    bool m_bAlignYawAngle;
    float m_fAlignYawAngle;
    __int8 m_bActivateButtonPrompt : 1;
    __int8 m_bCloseCombatImpactEventSent : 1;
    __int8 m_bCloseCombatKillEventSent : 1;
    ZInventorySlot* m_pHumanShieldWeaponCandidateSlot;
    float m_afAimHorizontalWeights[8];
    float m_afAimVerticalWeights[8];
    float m_fGrabHumanShieldFraction;
    float m_fAimBlendInFraction;
    float m_fKillHumanShieldFraction;
    float m_fDropWeaponFraction;
    float m_fTakeWeaponFraction;
    float m_fRagdollFraction;
    float m_fAimFraction;
    float m_fRawInputX;
    float m_fRawInputY;
    float m_fInputX;
    float m_fInputY;
    float m_fInputVelocity;
    SInputRestriction m_InputRestriction;
    bool m_bCCScaleActor;
    float m_fCCScaleUpWindowStartTime;
    float m_fCCScaleUpWindowEndTime;
    float m_fCCScaleDownWindowStartTime;
    float m_fCCScaleDownWindowEndTime;
    float m_fCCScaleUpBlend;
    float m_fCCScaleDownBlend;

    enum EStrafeState : __int32
    {
        eStateForward = 0x0,
        eStateLeft = 0x1,
        eStateRight = 0x2,
        eStateBackward = 0x3,
        eStateLast = 0x4
    };
};
