#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector3.h"

class SRenderPostfilterParametersSpatialBlur : public SRenderPostfilterParametersBase
{
public:
    SVector3 m_vCenter;
    float m_fBlurStart;
    float m_fBlurFade;
    float m_fBlurriness;
};
