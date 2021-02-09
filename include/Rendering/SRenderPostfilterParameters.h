#pragma once

#include "SRenderPostfilterParametersColorCorrection.h"
#include "SRenderPostfilterParametersDepthOfField.h"
#include "SRenderPostfilterParametersSpatialBlur.h"
#include "SRenderPostfilterParametersDistortionBarrel.h"
#include "SRenderPostfilterParametersDistortionWobble.h"
#include "SRenderPostfilterParametersDoubleVision.h"
#include "SRenderPostfilterParametersFastFog.h"
#include "SRenderPostfilterParametersFog.h"
#include "SRenderPostfilterParametersGaussianBlur.h"
#include "SRenderPostfilterParametersHDR.h"
#include "SRenderPostfilterParametersMisc.h"
#include "SRenderPostfilterParametersMotionBlur.h"
#include "SRenderPostfilterParametersNoise.h"
#include "SRenderPostfilterParametersRadialBlur.h"
#include "SRenderPostfilterParametersScreenDecals.h"
#include "SRenderPostfilterParametersSSAO.h"
#include "SRenderPostfilterParametersVideoEffects.h"
#include "SRenderPostfilterParametersVignette.h"

class alignas(16) SRenderPostfilterParameters
{
public:
    SRenderPostfilterParametersColorCorrection m_ColorCorrection;
    SRenderPostfilterParametersDepthOfField m_DepthOfField;
    SRenderPostfilterParametersSpatialBlur m_SpatialBlur;
    SRenderPostfilterParametersDistortionBarrel m_DistortionBarrel;
    SRenderPostfilterParametersDistortionWobble m_DistortionWobble;
    SRenderPostfilterParametersDoubleVision m_DoubleVision;
    SRenderPostfilterParametersFastFog m_FastFog;
    SRenderPostfilterParametersFog m_Fog;
    SRenderPostfilterParametersGaussianBlur m_GaussianBlur;
    SRenderPostfilterParametersHDR m_HDR;
    SRenderPostfilterParametersMisc m_Misc;
    SRenderPostfilterParametersMotionBlur m_MotionBlur;
    SRenderPostfilterParametersNoise m_Noise;
    SRenderPostfilterParametersRadialBlur m_RadialBlur;
    SRenderPostfilterParametersScreenDecals m_ScreenDecals;
    SRenderPostfilterParametersSSAO m_SSAO;
    SRenderPostfilterParametersVideoEffects m_VideoEffects;
    SRenderPostfilterParametersVignette m_Vignette;
    unsigned int m_nPostfilterEnabledMask;
    unsigned int m_nPostfilterGBufferUsageMask;
    unsigned int m_nPostfilterLastModifiedMask;
    float m_fSniperBlur;
};
