#pragma once

#include "SRenderPostfilterParametersBase.h"

class SRenderPostfilterParametersNoise : public SRenderPostfilterParametersBase
{
public:
    float m_fScale;
    float m_fIntensity;
};
