#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector2.h"

class alignas(4) SRenderPostfilterParametersDistortionWobble : public SRenderPostfilterParametersBase
{
public:
    float m_fScale;
    SVector2 m_vWobbleWaveLength;
    SVector2 m_vWobbleSpeed;
    bool m_bUseRealTime;
};
