#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector2.h"

struct SRenderPostfilterParametersRadialBlur : SRenderPostfilterParametersBase
{
	float m_fBlurriness;
	SVector2 m_vRadialCenter;
	float m_fRadialBlurStart;
	float m_fRadialBlurFadeFactor;

	SRenderPostfilterParametersRadialBlur() = default;
	~SRenderPostfilterParametersRadialBlur() = default;
	void Lerp(const SRenderPostfilterParametersRadialBlur& source, const SRenderPostfilterParametersRadialBlur& target, float fLerp, unsigned int nLerpState);
};
