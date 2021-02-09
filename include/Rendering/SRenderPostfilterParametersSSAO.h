#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector2.h"
#include "SVector4.h"

class SRenderPostfilterParametersSSAO : public SRenderPostfilterParametersBase
{
public:
    float m_fOcclusionRange;
    float m_fSSAOStrength;
    float m_fFarDistance;
    SVector2 m_vSampleRadii;
    SVector4 m_vColor;
};
