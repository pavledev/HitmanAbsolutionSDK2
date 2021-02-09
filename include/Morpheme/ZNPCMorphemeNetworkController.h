#pragma once

#include "ZActor.h"
#include "ZAnimatedActor.h"
#include "ELogState.h"
#include "ZAnimProgramBase.h"
#include "EActorEmotionState.h"
#include "IActListener.h"
#include "EMoveSpeed.h"

class ZNPCMorphemeNetworkController
{
public:
    ZActor* m_pActor;
    ZMorphemeNetworkInstance* m_pNetwork;
    ZAnimatedActor* m_pAnimatedActor;
    ZMorphemeNetworkInstance* m_pDynamicAct1CN;
    ZMorphemeNetworkInstance* m_pDynamicAct2CN;
    unsigned int m_paramRandomCN1;
    unsigned int m_paramRandomCN2;
    EActorEmotionState m_eReactionTargetState;
    float m_secondsWhilePlayingReaction;
    float m_reactionDurationInSeconds;
    unsigned int m_countActLoops;
    IActListener* m_pActListener;
    __int8 m_bActInFullbodySignaled : 1;
    __int8 m_bActResumeOriginalPosition : 1;
    __int8 m_bUpperBodyOnly : 1;
    __int8 m_bIsLeaningAtWindow : 1;
    __int8 m_bEnableNPCHitmanCollision : 1;
    SMatrix m_mActStartMatrix;
    float m_fTimeToStartFullBodyBlend;
    float m_fActUpperBodyBlendTime;
    float m_fActBlendTime;
    unsigned int m_nodeTargetAct;
    unsigned int m_nodeTargetReaction;
    __int8 m_bActShootRequested : 1;
    __int8 m_bActBlindfireRequested : 1;
    __int8 m_bEnableOffHandIK : 1;
    __int8 m_bOffHandOffsetSet : 1;
    float m_fRecoilWeight;
    float m_fRecoilFraction;
    float m_fImpactTime;
    float m_fDeathAnimationDuration;
    __int8 m_bDeathRagdollActivated : 1;
    __int8 m_bAllowDeathAnimations : 1;
    __int8 m_bDisableImpactAndDeathAnimations : 1;
    float m_transitionTranslationScaling;
    float m_endTransitionRotationScaling;
    float4 m_wsGroundCorrectionTargetPosition;
    float4 m_wsGroundCorrectionTargetDirection;
    EMoveSpeed m_eTransitionMoveSpeed;
    float m_timeToFullStop;
    float m_fCurrentTimeDelta;
    float4 m_wsRequestedAimPosition;
    float4 m_wsRequestedLookPosition;
    unsigned int m_eventLastFootstep;
    __int8 m_bRightFootEventTriggered : 1;
    __int8 m_bLeftFootEventTriggered : 1;
    unsigned int nodeCurrentEmotionState;
    unsigned int nodeCurrentLocomotion;
    unsigned int nodeCurrentMove;
    unsigned int nodeCurrentMoveToStand;
    unsigned int nodeCurrentMoveToStandMoveToStandSelect;
    unsigned int nodeCurrentStand;
    unsigned int nodeCurrentStandToMove;
    unsigned int nodeCurrentStandToMoveStandToMoveSelect;
    unsigned int nodeCurrentReposition;
    unsigned int nodeCurrentRepositionStandSelect;
    ELogState m_eLogState;
    ZAnimProgramBase* m_pCurrentProgram;
    __int8 m_bEnableGroundCorrection : 1;
    float4 m_wsGroundCorrectionTrans;
    float4 m_wsGroundCorrectionDir;
    float4 m_csGroundCorrectionAlignDir;
    float m_fGroundCorrectionTranslationThreshold;
    float m_fGroundCorrectionAttitudeThreshold;
    int idMeshHeadBone;
    int idMeshNeckBone;
    SMatrix m_csHeadTransform;
    SMatrix m_csNeckTransform;
    int idMeshPoseMatchBones[19];
    float4 m_csCurrentAimDirection;
    float4 m_csCurrentLookDirection;
};
