#pragma once

#include "SRenderPostfilterPerScreenDecalParameters.h"
#include "SVector4.h"

struct SRenderPostfilterPerScreenDecalParametersInternal : SRenderPostfilterPerScreenDecalParameters
{
	float m_fTimeCreated;
	float m_fDeviationScale;
	SVector4 m_vTexScaleOffset;
	bool m_bPair;

	SRenderPostfilterPerScreenDecalParametersInternal() = default;
	~SRenderPostfilterPerScreenDecalParametersInternal() = default;
};
