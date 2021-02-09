#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZSpatialEntity.h"
#include "ZSoundMultiLayerControl.h"
#include "ZSoundOcclusionProbe.h"

class __declspec(align(16)) ZSoundMultiLayerMixer : public ZEntityImpl
{
public:
    TEntityRef<ZSpatialEntity> m_pSpatialEntity;
    float m_fMinDistance;
    float m_fMaxDistance;
    float m_fSpatialAttenuation;
    float m_fSpatialFalloffAttenuation;
    float m_fDirectionalAttenuation;
    float m_fAttenuationL;
    float m_fAttenuationR;
    float m_fAttenuationC;
    float m_fAttenuationLFE;
    float m_fAttenuationBackL;
    float m_fAttenuationBackR;
    float m_fAttenuationSideL;
    float m_fAttenuationSideR;
    bool m_bRaycastOcclusion;
    float m_fOcclusionAttenuation;
    float m_fOcclusionMaxRadius;
    float m_fOcclusionMinRadius;
    float m_fOcclusionMaxDistOverride;
    float m_fOcclusionSmoothingOverride;
    TEntityRef<ZSoundMultiLayerControl> m_pControlEntity;
    TEntityRef<ZSpatialEntity> m_pSpatialAspect;
    float4 m_vPosition;
    float m_fSpeakerLevels[8];
    float m_fBaseVolume[8];
    float m_fSpatialBaseVolume;
    float m_fSpatialFalloffVolume;
    float m_fDirectionalVolume;
    float m_fOcclusionVolume;
    ZSoundOcclusionProbe m_OcclusionProbe;
    float4 m_vOcclusionTargetPos;
    unsigned __int64 m_nFrameUpdateTag;
};
