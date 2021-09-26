#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector2.h"

struct SRenderPostfilterParametersDistortionWobble : SRenderPostfilterParametersBase
{
	float m_fScale;
	SVector2 m_vWobbleWaveLength;
	SVector2 m_vWobbleSpeed;
	bool m_bUseRealTime;

	SRenderPostfilterParametersDistortionWobble() = default;
	~SRenderPostfilterParametersDistortionWobble() = default;
	void Lerp(const SRenderPostfilterParametersDistortionWobble& source, const SRenderPostfilterParametersDistortionWobble& target, float fLerp, unsigned int nLerpState);
};
