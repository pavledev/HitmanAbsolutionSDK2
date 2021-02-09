#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector2.h"

class SRenderPostfilterParametersRadialBlur : public SRenderPostfilterParametersBase
{
public:
    float m_fBlurriness;
    SVector2 m_vRadialCenter;
    float m_fRadialBlurStart;
    float m_fRadialBlurFadeFactor;
};
