#pragma once

#include "SRenderPostfilterPerScreenDecalParameters.h"
#include "SVector4.h"

class alignas(4) SRenderPostfilterPerScreenDecalParametersInternal : public SRenderPostfilterPerScreenDecalParameters
{
public:
    float m_fTimeCreated;
    float m_fDeviationScale;
    SVector4 m_vTexScaleOffset;
    bool m_bPair;
};
