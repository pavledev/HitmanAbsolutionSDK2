#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector2.h"

class SRenderPostfilterParametersDistortionBarrel : public SRenderPostfilterParametersBase
{
public:
    SVector2 m_vBarrel;
};
