#pragma once

#include "SRenderPostfilterParametersBase.h"

struct SRenderPostfilterParametersMisc : SRenderPostfilterParametersBase
{
	float m_fSaturation;

	SRenderPostfilterParametersMisc() = default;
	~SRenderPostfilterParametersMisc() = default;
	void Lerp(const SRenderPostfilterParametersMisc& src, const SRenderPostfilterParametersMisc& dst, float fLerp, unsigned int nLerpState);
};
