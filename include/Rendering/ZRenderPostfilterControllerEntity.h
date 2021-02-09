#pragma once

#include "ZRenderableEntity.h"
#include "IRenderPostfilterControllerEntity.h"

class alignas(16) ZRenderPostfilterControllerEntity : public ZRenderableEntity, public IRenderPostfilterControllerEntity
{
public:
    ZEntityRef m_PostfilterParametersEntity;
    ZEntityRef m_GamePostfilterControllerEntity;
    bool m_bLerpGaussian;
    bool m_bLerpMotion;
    bool m_bLerpRadial;
    bool m_bLerpSpatial;
    bool m_bLerpColorCorrection;
    bool m_bLerpDepthOfField;
    bool m_bLerpDistortionBarrel;
    bool m_bLerpDistortionWobble;
    bool m_bLerpDoubleVision;
    bool m_bLerpFastFog;
    bool m_bLerpFog;
    bool m_bLerpHDR;
    bool m_bLerpMisc;
    bool m_bLerpNoise;
    bool m_bLerpSSAO;
    bool m_bLerpVideo;
    bool m_bLerpVignette;
    float m_fBlendTime;
    bool m_bRoomLerpEnabled;
    float m_fLuminance;
    ZEntityRef m_CurrentPostfilterParametersEntity;
    SRenderPostfilterParameters m_sourcePostfilterParameters;
    SRenderPostfilterParameters m_targetPostfilterParameters;
    SRenderPostfilterParameters m_currentPostfilterParameters;
    SRenderPostfilterParameters m_roomParameters;
    SRenderPostfilterPerScreenDecalParametersInternal m_RingBuffer[64];
    unsigned int m_nNumDecalsAdded;
    int m_nLerpState;
    float m_fLerpValue;
    float m_fLerpTime;
    unsigned int m_nLerpMask;

    enum UnkEnum : __int32
    {
        eLerpStopState = 0x0,
        eLerpProgressState = 0x1,
        eLerpStartState = 0x2
    };
};
