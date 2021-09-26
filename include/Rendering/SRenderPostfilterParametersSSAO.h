#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector2.h"
#include "SVector4.h"

struct SRenderPostfilterParametersSSAO : SRenderPostfilterParametersBase
{
	float m_fOcclusionRange;
	float m_fSSAOStrength;
	float m_fFarDistance;
	SVector2 m_vSampleRadii;
	SVector4 m_vColor;

	SRenderPostfilterParametersSSAO() = default;
	~SRenderPostfilterParametersSSAO() = default;
	void Lerp(const SRenderPostfilterParametersSSAO& source, const SRenderPostfilterParametersSSAO& target, float fLerp, unsigned int nLerpState);
};
