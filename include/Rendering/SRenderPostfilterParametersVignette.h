#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector4.h"

struct float4;

struct SRenderPostfilterParametersVignette : SRenderPostfilterParametersBase
{
	SVector4 m_vParams;
	SVector4 m_vGradientLightParams;

	static const float4 s_vDefaultVignette;

	SRenderPostfilterParametersVignette() = default;
	~SRenderPostfilterParametersVignette() = default;
	void Lerp(const SRenderPostfilterParametersVignette& source, const SRenderPostfilterParametersVignette& target, const float4& vLerp, unsigned int nLerpState);
};
