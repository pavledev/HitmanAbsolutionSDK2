#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "float4.h"
#include "SVector4.h"
#include "SVector2.h"
#include "ERenderPostfilterGlareType.h"

struct SRenderPostfilterParametersHDR : SRenderPostfilterParametersBase
{
	float4 m_vLensFlareColorA;
	float4 m_vLensFlareColorB;
	float4 m_vLensFlareColorC;
	float4 m_vLensFlareColorD;
	float4 m_vLensFlareThresholds;
	SVector4 m_vHDRAdaptionData;
	SVector2 m_vHDRBloomData;
	SVector4 m_vHDRBloomData2;
	bool m_bGlareEnabled;
	bool m_bLensFlareEnabled;
	ERenderPostfilterGlareType m_eGlareType;

	SRenderPostfilterParametersHDR() = default;
	~SRenderPostfilterParametersHDR() = default;
	float* HDRMiddleGray();
	float* HDRGlareSaturation();
	float* HDRBrightPassThreshold();
	float* HDRLensFlareAttenuation();
	SVector2* HDRAdaptionRange();
	SVector2* HDRAdaptionSpeed();
	float* HDRBloomScale();
	float* HDRStarScale();
	void Lerp(const SRenderPostfilterParametersHDR& source, const SRenderPostfilterParametersHDR& target, const float4& vLerp, unsigned int nLerpState);
};
