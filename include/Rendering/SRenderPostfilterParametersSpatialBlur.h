#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector3.h"

struct SRenderPostfilterParametersSpatialBlur : SRenderPostfilterParametersBase
{
	SVector3 m_vCenter;
	float m_fBlurStart;
	float m_fBlurFade;
	float m_fBlurriness;

	SRenderPostfilterParametersSpatialBlur() = default;
	~SRenderPostfilterParametersSpatialBlur() = default;
};
