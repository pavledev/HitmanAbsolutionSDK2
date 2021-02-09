#pragma once

#include "ECCNodeType.h"
#include "EAttackChoice.h"
#include "SCloseCombatEffect.h"
#include "ZGameTime.h"
#include "ECCNodeSubtype.h"

class SAnimNodeHitman
{
public:
    unsigned int m_anNodeId[2];
    unsigned int m_anParentNodeId[2];
    unsigned int m_nNodeNum;
    ECCNodeType m_eNodeType;
    float m_fDuration;
    float m_fStartFraction;
    float m_fTransitIdleFraction;
    float m_fAllowTransitEndStand;
    float m_fAllowTransitEndCrouch;
    float m_fCornerDoneGrabFraction;
    float m_fCornerSideFraction;
    float m_fCornerBackFraction;
    float m_fChangeOutfit;
    float m_fGotoSequence;
    float m_fStartAttackFraction;
    float m_fTransitFraction;
    float m_fActivateNPCRagdoll;
    float m_fActivateHMRagdoll;
    float m_fActivateEarlyNPCRagdoll;
    float m_fDisarmTakeWeapon;
    float m_fDisarmNPCDropWeapon;
    float m_fNPCEquipGun;
    float m_fNPCFireGun;
    float m_fNPCDieInStangle;
    float m_afHitmanFireGun[2];
    float m_afChoiceFaction[2];
    EAttackChoice m_aChoice[2];
    unsigned int m_nNumChoices;
    float m_afBreakoutFaction[9];
    int m_aiBreakoutIndex[9];
    int m_nNumBreakouts;
    float m_afAttackWindowFaction[9];
    int m_nNumAttackWindows;
    float m_afScaleDownFaction[4];
    int m_nNumScaleWindows;
    float m_afSlowdownWindowFaction[9];
    int m_nNumSlowdownWindows;
    float m_fTimeBlendInFaction;
    float m_fBreakIntoChainFaction;
    float m_fAllowNPCInterrupt;
    float m_fStartStrangle;
    float m_fTimeBlendCameraOut;
    float m_afImpactFraction[4];
    unsigned int m_nNumImpacts;
    SCloseCombatEffect m_aEffect[8];
    unsigned int m_nNumEffects;
    float m_afCamSwitchFraction[4];
    int m_aiCamId[4];
    float m_fStartBlendToCam;
    float m_fFallTime;
    bool m_bSafeAnim;
    bool m_bMirrorAnim;
    bool m_bUseRagdollSpeedMultiplier;
    float m_fGroundTranslation;
    ZGameTime m_LastTimePlayed;
    ECCNodeSubtype m_eNodeSubtype;
    float m_afIndexEffectFraction[4];
    unsigned int m_anEffectEvent[4];
    unsigned int m_nNumIndexEffects;
};
