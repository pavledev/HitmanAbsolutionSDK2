#pragma once

#include "SRenderPostfilterParametersBase.h"

struct SRenderPostfilterParametersGaussianBlur : SRenderPostfilterParametersBase
{
	float m_fBlurriness;

	SRenderPostfilterParametersGaussianBlur() = default;
	~SRenderPostfilterParametersGaussianBlur() = default;
	void Lerp(const SRenderPostfilterParametersGaussianBlur& source, const SRenderPostfilterParametersGaussianBlur& target, float fLerp);
};
