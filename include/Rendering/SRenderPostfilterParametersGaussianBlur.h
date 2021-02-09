#pragma once

#include "SRenderPostfilterParametersBase.h"

class SRenderPostfilterParametersGaussianBlur : public SRenderPostfilterParametersBase
{
public:
    float m_fBlurriness;
};
