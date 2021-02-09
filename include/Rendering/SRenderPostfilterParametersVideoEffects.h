#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector2.h"

class SRenderPostfilterParametersVideoEffects : public SRenderPostfilterParametersBase
{
public:
    SVector2 m_vVideoScale;
    SVector2 m_vVideoOffset;
    float m_fVideoHorizSkew;
    float m_fVideoHorizBend;
    float m_fVideoFineShaking;
    float m_fVideoColorNoise;
};