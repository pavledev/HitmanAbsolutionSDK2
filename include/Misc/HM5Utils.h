#pragma once

#include "SVector3.h"
#include "ZMorphemeNetworkInstance.h"
#include "float1.h"
#include "SMatrix43.h"

namespace HM5Utils
{
    struct SPelvisSimpleRotationCorrection
    {
        unsigned int m_nAnimID;
        int m_nPelvisMeshID;
        ZMorphemeNetworkInstance* m_pNetwork;
        SMatrix m_mvPelvisDelta;
        float m_fStartBlendFraction;
        float m_fEndBlendFraction;

        SPelvisSimpleRotationCorrection() = default;
        ~SPelvisSimpleRotationCorrection() = default;
    };

    struct SAnimBlend
    {
        enum EBlendParam
        {
            eBlend_Default = 0,
            eBlend_AnimFraction = 1,
            eBlend_TranslationX = 2,
            eBlend_TranslationY = 3,
            eBlend_TranslationZ = 4,
            eBlend_RotationZ = 5
        };

        enum EMirrorParam
        {
            eMirror_Default = 0,
            eMirror_ForceON = 1,
            eMirror_ForceOFF = 2
        };

        enum EZRotationOption
        {
            eZRotation_Default = 0,
            eZRotation_Ignore = 1,
            eZRotation_ForcePositive = 2,
            eZRotation_ForceNegative = 3
        };

        SVector3 m_vTranslationBlend;
        float m_fRotationZBlend;
        float m_fRotationZ;
        float m_fBlendFraction;
        float m_fSelectedBlendFraction;
        float m_fStartFraction;
        float m_fEndFraction;
        unsigned int m_nAnimId;
        ZMorphemeNetworkInstance* m_pNetwork;
        EZRotationOption m_eZRotation;
        bool m_bXYTranslationBlend;
        float m_fXYTranslation;
        EMirrorParam m_eMirrorParam;
        EBlendParam m_eBlendParam;
        SMatrix43 m_mDelta;

        SAnimBlend() = default;
        ~SAnimBlend() = default;
        float GetTranslationXBlend() const;
        float GetTranslationYBlend() const;
        float GetTranslationZBlend() const;
        float GetRotationZBlend() const;
        float GetSelectedBlend() const;
        bool GetMirroring() const;
    };

    struct SYawPitchBlend
    {
        float m_fDeltaYaw;
        float m_fDeltaPitch;
        float4 m_vDeltaPos;

        SYawPitchBlend() = default;
        ~SYawPitchBlend() = default;
    };

    struct SBlendParamFractions
    {
        float m_fStartFraction;
        float m_fEndFraction;

        SBlendParamFractions() = default;
        ~SBlendParamFractions() = default;
    };

    struct SPelvisRotationCorrection
    {
        int m_nPelvisMeshId;
        ZMorphemeNetworkInstance* m_pNetwork;
        unsigned int m_nAnimId;
        SMatrix m_mRotationStartDelta;
        float4 m_vTranslationStartDelta;
        SMatrix m_mRotationEndDelta;
        float4 m_vTranslationEndDelta;
        float m_fStartDeltaBlendOutFraction;
        float m_fEndDeltaBlendInFraction;

        SPelvisRotationCorrection() = default;
        ~SPelvisRotationCorrection() = default;
    };

    struct SCollisionPlane
    {
        float4 m_vPlaneEquation;
        float4 m_vPlaneNormal;
        float4 m_vClosestPoint;
        float4 m_vMoveVec;
        float1 m_vMoveVecLengthSq;

        SCollisionPlane() = default;
        ~SCollisionPlane() = default;
    };
};
