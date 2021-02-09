#pragma once

#include "TEntityRef.h"
#include "IMorphemeEntity.h"
#include "ELookAtConstraintType.h"
#include "EAimConstraintType.h"
#include "sFeetInfo.h"
#include "sHandInfo.h"
#include "sHeadInfo.h"
#include "AimMode.h"
#include "ZGameTime.h"
#include "HandReTargetMode.h"
#include "ZAimBuffer.h"
#include "sMuzzleInfo.h"
#include "sLedgeInfo.h"
#include "sLedgeFeetLockInfo.h"
#include "ZHitmanMorphemePostProcessorLedgeHangCallback.h"
#include "sLedgeHangBoneBuffer.h"
#include "ZHitmanMorphemePostProcessorFiberWireCallback.h"
#include "SSBAimInfo.h"
#include "SRecoilEntry.h"
#include "SImpactAnimEntry.h"
#include "SLedgeAimInfo.h"
#include "ZMapPoly.h"
#include "SHM5AimInfo.h"
#include "SHM5LookAtInfo.h"

class ZHitmanMorphemePostProcessor
{
public:
    TEntityRef<IMorphemeEntity> m_pMorpheme;
    bool m_bActive;
    ELookAtConstraintType m_ConstraintType;
    EAimConstraintType m_AimConstraintType;
    float4 m_vAimDir[2];
    float4 m_vAimPos[2];
    float4 m_vAimPosWorld[2];
    float4 m_vDestAimPosWorld[2];
    int m_nAimBoneId;
    float m_AimWeights[7];
    int m_nAimDepth;
    float m_aAim;
    float m_bAim;
    int m_nAimDirBoneMajorAxis;
    int m_nAimDirBoneId[2];
    sFeetInfo m_FeetInfo;
    sHandInfo m_HandInfo;
    sHeadInfo m_HeadInfo;
    SMatrix m_mvHitman;
    float m_fMinForeArmRot;
    AimMode::eAimMode m_eAimMode;
    float m_fAimOverallWeight;
    ZGameTime m_tAimStartTime[2];
    HandReTargetMode::eHandReTargetMode m_eHandRetargetMode;
    float m_fAimLookAtWeight;
    ZAimBuffer m_AimBoneBuffer;
    sMuzzleInfo m_MuzzleInfo[2];
    bool m_bAimMirrored;
    float m_fTwoHandLookAtAimBound;
    sLedgeInfo m_LedgeInfo;
    sLedgeFeetLockInfo m_LedgeFeetLockInfo;
    ZHitmanMorphemePostProcessorLedgeHangCallback* m_pLHCallBack;
    alignas(16) sLedgeHangInfos m_LedgeHangInfo;
    sLedgeHangInfos m_OldLedgeHangInfo;
    sLedgeHangBoneBuffer m_LHBoneBuffer;
    float m_fLHCurrentWeight;
    float m_fLHTargetWeight;
    ZHitmanMorphemePostProcessorFiberWireCallback* m_pFWCallback;
    sFiberWireInfos m_FWInfo;
    sFiberWireInfos m_FWOldInfo;
    float m_fFWTargetWeight;
    float m_fFWCurrentWeight;
    float m_fFWBlendOutTime;
    SSBAimInfo m_sSBAimInfo;
    int m_anSBAimBones[8];
    float m_afSBOneHandHWeights[8];
    float m_afSBOneHandVWeights[8];
    float m_afSBOneHandHLWeights[8];
    float m_afSBOneHandVLWeights[8];
    float m_afSBTwoHandHWeights[8];
    float m_afSBTwoHandVWeights[8];
    float m_afSBOneHandHLookAtWeights[8];
    float m_afSBOneHandVLookAtWeights[8];
    SQuaternion m_aqSBAimDelta[8];
    int m_anSBAimPoseBones[17];
    SQV m_asqvSBAimPose[17];
    unsigned int m_nSBAimPose;
    float4 m_vPoseLookAtPos;
    SMatrix m_mvPelvisOffset;
    SRecoilEntry m_aRecoils[3];
    int m_anRecoilBones[15];
    unsigned int m_nRecoilRHandIndex;
    unsigned int m_nRecoilLHandIndex;
    bool m_bRecoilBonesInitilized;
    SQV m_aRecoilAnimCache[15];
    unsigned int m_nRecoilAnimId;
    bool m_bRecoilMirrorAnim;
    bool m_bRecoilActive;
    unsigned int m_anRecoilMask[15];
    SImpactAnimEntry m_ImpactAnim;
    unsigned int m_anImpactAnimIds[4];
    int m_anImpactBones[10];
    bool m_abTwoHandedBone[10];
    bool m_bImpactBonesInitilized;
    SQuaternion m_aImpactAnimCache[4][10];
    TArrayRef<SQV> m_BoneCache;
    float m_fTimeMultiplier;
    unsigned int m_nComponentSelector;
    SLedgeAimInfo m_LedgeAimInfo;
    ZMapPoly m_MapPoly;
    float m_fSneakFraction;
    SHM5AimInfo m_AimInfo;
    float m_afHorizontalWeights[8];
    float m_afVerticalWeights[8];
    int m_anAimBones[8];
    int m_anAimLookAtBones[2];
    bool m_bAimAndLookAtBonesInitialized;
    SQuaternion m_aAimPoseBlendBuffer[8];
    SQuaternion m_aAimDeltaBuffer[8];
    SQuaternion m_aAimLookAtPoseBlendBuffer[2];
    SQuaternion m_aAimLookAtDeltaBuffer[2];
    int m_anLookAtBones[6];
    float m_afLookAtHorizontalWeights[6];
    float m_afLookAtVerticalWeights[6];
    SQuaternion m_aqLookAtDeltaBuffer[6];
    SQuaternion m_aqLookAtPoseBuffer[6];
    SHM5LookAtInfo m_sLookAtInfo;

    struct InitializeRecoilBones
    {
        struct __l5
        {
            struct SRecoilData
            {
                unsigned int m_nBoneId;
                unsigned int m_nRecoilFlags;
            };
        };
    };

    struct alignas(4) InitializeImpactBones
    {
        struct __l5
        {
            struct SImpactBone
            {
                unsigned int m_nBoneId;
                bool m_bTwoHandedBone;
            };
        };
    };
};
