#pragma once

#include "SVector3.h"
#include "ZMorphemeNetworkInstance.h"
#include "float1.h"

class HM5Utils
{
public:
    struct SAnimBlend
    {
        SVector3 m_vTranslationBlend;
        float m_fRotationZBlend;
        float m_fRotationZ;
        float m_fBlendFraction;
        float m_fSelectedBlendFraction;
        float m_fStartFraction;
        float m_fEndFraction;
        unsigned int m_nAnimId;
        ZMorphemeNetworkInstance* m_pNetwork;

        enum EZRotationOption : __int32
        {
            eZRotation_Default = 0x0,
            eZRotation_Ignore = 0x1,
            eZRotation_ForcePositive = 0x2,
            eZRotation_ForceNegative = 0x3,
        } m_eZRotation;

        bool m_bXYTranslationBlend;
        float m_fXYTranslation;

        enum EMirrorParam : __int32
        {
            eMirror_Default = 0x0,
            eMirror_ForceON = 0x1,
            eMirror_ForceOFF = 0x2,
        } m_eMirrorParam;

        enum EBlendParam : __int32
        {
            eBlend_Default = 0x0,
            eBlend_AnimFraction = 0x1,
            eBlend_TranslationX = 0x2,
            eBlend_TranslationY = 0x3,
            eBlend_TranslationZ = 0x4,
            eBlend_RotationZ = 0x5,
        } m_eBlendParam;

        SMatrix43 m_mDelta;
    };

    struct SYawPitchBlend
    {
        float m_fDeltaYaw;
        float m_fDeltaPitch;
        float4 m_vDeltaPos;
    };

    struct SBlendParamFractions
    {
        float m_fStartFraction;
        float m_fEndFraction;
    };

    class alignas(16) SPelvisRotationCorrection
    {
    public:
        int m_nPelvisMeshId;
        ZMorphemeNetworkInstance* m_pNetwork;
        unsigned int m_nAnimId;
        SMatrix m_mRotationStartDelta;
        float4 m_vTranslationStartDelta;
        SMatrix m_mRotationEndDelta;
        float4 m_vTranslationEndDelta;
        float m_fStartDeltaBlendOutFraction;
        float m_fEndDeltaBlendInFraction;
    };

    class alignas(16) SPelvisSimpleRotationCorrection
    {
    public:
        unsigned int m_nAnimID;
        int m_nPelvisMeshID;
        ZMorphemeNetworkInstance* m_pNetwork;
        SMatrix m_mvPelvisDelta;
        float m_fStartBlendFraction;
        float m_fEndBlendFraction;
    };

    class SCollisionPlane
    {
    public:
        float4 m_vPlaneEquation;
        float4 m_vPlaneNormal;
        float4 m_vClosestPoint;
        float4 m_vMoveVec;
        float1 m_vMoveVecLengthSq;
    };
};
