#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector4.h"
#include "EPostFilterDofBlurType.h"

struct SRenderPostfilterParametersDepthOfField : SRenderPostfilterParametersBase
{
	SVector4 m_vFocalData;
	float m_fBlurriness;
	float m_fLensBlur;
	EPostFilterDofBlurType m_eBlurQuality;
	bool m_bForegroundBlur;

	SRenderPostfilterParametersDepthOfField() = default;
	~SRenderPostfilterParametersDepthOfField() = default;
	void Lerp(const SRenderPostfilterParametersDepthOfField& source, const SRenderPostfilterParametersDepthOfField& target, float fLerp, unsigned int nLerpState);
	float* DOFFocalDistance();
	float* DOFFieldFocalRange();
	float* DOFFocalFadeNear();
	float* DOFFocalFadeFar();
};
