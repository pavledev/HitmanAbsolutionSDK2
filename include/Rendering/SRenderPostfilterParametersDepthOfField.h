#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector4.h"
#include "EPostFilterDofBlurType.h"

class alignas(4) SRenderPostfilterParametersDepthOfField : public SRenderPostfilterParametersBase
{
public:
    SVector4 m_vFocalData;
    float m_fBlurriness;
    float m_fLensBlur;
    EPostFilterDofBlurType m_eBlurQuality;
    bool m_bForegroundBlur;
};
