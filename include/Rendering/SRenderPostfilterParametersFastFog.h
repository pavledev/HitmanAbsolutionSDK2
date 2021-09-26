#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector4.h"

struct SRenderPostfilterParametersFastFog : SRenderPostfilterParametersBase
{
	SVector4 m_vParams;

	SRenderPostfilterParametersFastFog() = default;
	~SRenderPostfilterParametersFastFog() = default;
	void Lerp(const SRenderPostfilterParametersFastFog& source, const SRenderPostfilterParametersFastFog& target, float fLerp, unsigned int nLerpState);
};
