#pragma once

#include "SRenderPostfilterParametersBase.h"

struct SRenderPostfilterParametersMotionBlur : SRenderPostfilterParametersBase
{
	float m_fBlurriness;

	SRenderPostfilterParametersMotionBlur() = default;
	~SRenderPostfilterParametersMotionBlur() = default;
};
