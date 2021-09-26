#pragma once

#include "SRenderPostfilterParametersBase.h"

struct SRenderPostfilterParametersNoise : SRenderPostfilterParametersBase
{
	float m_fScale;
	float m_fIntensity;

	SRenderPostfilterParametersNoise() = default;
	~SRenderPostfilterParametersNoise() = default;
	void Lerp(const SRenderPostfilterParametersNoise& source, const SRenderPostfilterParametersNoise& target, float fLerp, unsigned int nLerpState);
	void SetDisabled();
};
