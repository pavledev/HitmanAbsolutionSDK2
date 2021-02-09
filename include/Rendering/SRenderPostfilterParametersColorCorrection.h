#pragma once

#include "SRenderPostfilterParametersBase.h"

class alignas(4) SRenderPostfilterParametersColorCorrection : public SRenderPostfilterParametersBase
{
public:
    unsigned int m_Palette[7][256];
    float m_fNearRange;
    float m_fFarRange;
    unsigned int m_nVersion;
    bool m_bDepthRemapEnabled;
    bool m_bColorCorrectFar;
};
