#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector2.h"

struct SRenderPostfilterParametersVideoEffects : SRenderPostfilterParametersBase
{
	SVector2 m_vVideoScale;
	SVector2 m_vVideoOffset;
	float m_fVideoHorizSkew;
	float m_fVideoHorizBend;
	float m_fVideoFineShaking;
	float m_fVideoColorNoise;

	SRenderPostfilterParametersVideoEffects() = default;
	~SRenderPostfilterParametersVideoEffects() = default;
};
