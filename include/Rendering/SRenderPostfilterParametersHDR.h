#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "float4.h"
#include "SVector4.h"
#include "SVector2.h"
#include "ERenderPostfilterGlareType.h"

class SRenderPostfilterParametersHDR : public SRenderPostfilterParametersBase
{
public:
    float4 m_vLensFlareColorA;
    float4 m_vLensFlareColorB;
    float4 m_vLensFlareColorC;
    float4 m_vLensFlareColorD;
    float4 m_vLensFlareThresholds;
    SVector4 m_vHDRAdaptionData;
    SVector2 m_vHDRBloomData;
    SVector4 m_vHDRBloomData2;
    bool m_bGlareEnabled;
    bool m_bLensFlareEnabled;
    ERenderPostfilterGlareType m_eGlareType;
};
