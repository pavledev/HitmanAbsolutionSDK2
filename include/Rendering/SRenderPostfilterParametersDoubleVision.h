#pragma once

#include "SRenderPostfilterParametersBase.h"

struct SRenderPostfilterParametersDoubleVision : SRenderPostfilterParametersBase
{
	float m_fDoubleVisionStrength;
	float m_fDoubleVisionSpeed;
	float m_fDoubleVisionEyeSeparation;
	float m_fDoubleVisionSpeed1;
	float m_fDoubleVisionSpeed2;
	float m_fDoubleVisionScaleSpeed1;
	float m_fDoubleVisionScaleSpeed2;
	float m_fDoubleVisionMinScale;
	float m_fDoubleVisionMaxScale;
	float m_fDoubleVisionBlendSpeed;
	float m_fDoubleVisionBlendStrength;
	float m_fDoubleVisionTrailStrength;

	SRenderPostfilterParametersDoubleVision() = default;
	~SRenderPostfilterParametersDoubleVision() = default;
	void Lerp(const SRenderPostfilterParametersDoubleVision& source, const SRenderPostfilterParametersDoubleVision& target, float fLerp);
};
