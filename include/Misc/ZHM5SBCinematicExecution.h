#pragma once

#include "SHM5SBShared.h"
#include "ESBHand.h"
#include "ESBCinematicState.h"
#include "SSBConfiguration.h"
#include "SCinematicTags.h"

class alignas(16) ZHM5SBCinematicExecution
{
public:
    const SHM5SBShared* m_SBShared;
    float m_fMaxTimeMultiplier;
    unsigned int m_nCurrentTag;
    ZMapPoly m_MapPoly;
    ZMapPoly m_MapPolyZoom;
    float4 m_vAimPos;
    ESBHand m_eAimingHand;
    float m_fExecutionFraction;
    float m_afTimeSinceLastShot[2];
    bool m_bTriggeredPushed[2];
    bool m_bZoomHasBeenReleasedSinceStart;
    ESBCinematicState m_eCinematicState;
    SSBConfiguration m_ConfigurationShot;
    SSBConfiguration m_ConfigurationBulletImpact;
    SSBConfiguration m_ConfigurationHitmanView;
    SSBConfiguration m_ConfigurationBulletImpactPre;
    SSBConfiguration m_ConfigurationLastKill;
    unsigned int m_nCinematicTag;
    float m_fCinematicMultiplier;
    float m_fCinematicStateTime;
    float m_fLockExecutionFraction;
    float m_fHitmanViewFraction;
    unsigned int m_nLastZoomTag;
    unsigned int m_nLastHitmanTag;
    bool m_bPlayImpacts;
    bool m_bCinematicShotRightHand;
    unsigned int m_nSequenceElements;
    unsigned int m_nReverseShotIndex;
    unsigned int m_nCinematicIndex;
    bool m_bIsCinematic;
    bool m_bCinematicExit;
    bool m_bZoomActivated;
    bool m_bZoomStartLock;
    bool m_bZoomAllowed;
    bool m_bCheckTransitionToTargetView;
    HM5Utils::SAnimBlend m_sAnimBlend;
    SMatrix m_mvStart;
    SMatrix m_mvEnd;
    float m_fAnimFraction;
    float m_fAnimFractionStart;
    bool m_bAnimating;
    unsigned int m_nNumShotsAtAnimStart;
    const SSBAnim* m_pCurrentAnimation;
    const SSBAnim* m_pLastAnimation;
    SSBAimInfo m_SBAimInfo;
    ESBWeaponType m_eSBWeaponType;
    float m_fEndTimer;
    float4 m_vFilterAimPos;
    unsigned int m_nAimTag;
    float m_fMinTimeForHitmanView;
    SCinematicTags m_anCinematic[32];

    struct alignas(4) CalcCinematicSequence
    {
        struct __l2
        {
            struct SCinematicTag
            {
                unsigned int m_nTag;
                unsigned int m_nNumTags;
                unsigned int m_nCinCounter;
                bool m_bCinematic;
            };
        };
    };
};
