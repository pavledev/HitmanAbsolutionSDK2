#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector2.h"

struct float4;

struct SRenderPostfilterParametersDistortionBarrel : SRenderPostfilterParametersBase
{
	SVector2 m_vBarrel;

	SRenderPostfilterParametersDistortionBarrel() = default;
	~SRenderPostfilterParametersDistortionBarrel() = default;
	void Lerp(const SRenderPostfilterParametersDistortionBarrel& source, const SRenderPostfilterParametersDistortionBarrel& target, const float4& vLerp, unsigned int nLerpState);
};
