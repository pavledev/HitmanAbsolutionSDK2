#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector4.h"

class SRenderPostfilterParametersVignette : public SRenderPostfilterParametersBase
{
public:
    SVector4 m_vParams;
    SVector4 m_vGradientLightParams;
};
