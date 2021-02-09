#pragma once

#include "ZBoundedEntity.h"
#include "ISoundListenerPositionReceiver.h"
#include "ESOUND_3DROLLOFF_TYPE.h"
#include "TSharedValue.h"
#include "ZCurve.h"
#include "SFMODRolloffCurve.h"
#include "ZSoundOcclusionProbe.h"
#include "ZSoundPlayableBase.h"

class ZSoundBlendContainerExternalParameters;

class __declspec(align(16)) ZSoundSpatialParameter : public ZBoundedEntity, public ISoundListenerPositionReceiver
{
public:
    float m_fMinDistance;
    float m_fMaxDistance;
    ESOUND_3DROLLOFF_TYPE m_e3dRolloffType;
    float m_fInsideConeAngle;
    float m_fOutsideConeAngle;
    float m_fOutsideAttenuation;
    float m_fDopplerLevel;
    TSharedValue<ZCurve> m_RolloffCurve;
    float m_f3DWeight;
    SVector3 m_vRandomLocationInner;
    SVector3 m_vRandomLocationOuter;
    float m_fReverbLevelNear;
    float m_fReverbLevelFar;
    float m_fReverbRadius;
    bool m_bRaycastOcclusion;
    float m_fGeometryOcclusionFactor;
    bool m_bEnableFocusLowpass;
    float m_fOcclusionAttenuation;
    float m_fOcclusionMaxRadius;
    float m_fOcclusionMinRadius;
    float m_fOcclusionMaxDistOverride;
    float m_fOcclusionReverbAttenuation;
    float m_fOcclusionLowpassHigh;
    float m_fOcclusionLowpassLow;
    float m_fLowpassMaxDistance;
    float m_fLowpassMaxDistanceCutoff;
    float m_fLFEAttenuation;
    float4 m_vPos;
    float4 m_vPosRandomOffset;
    float4 m_vVelocity;
    float4 m_vOcclusionTargetPos;
    TSharedValue<SFMODRolloffCurve> m_aCustomRolloffCurve;
    unsigned int m_nMemOptimizedData;
    ZSoundOcclusionProbe m_OcclusionProbe;
    float m_fOcclusionSmoothingOverride;
    TEntityRef<ZSoundPlayableBase> m_parentEntity;
    TEntityRef<ZSoundBlendContainerExternalParameters> m_pBlendContainer;
};
