#pragma once

#include "SVector2.h"

struct SRenderPostfilterPerScreenDecalParameters
{
	SVector2 m_vPosition;
	float m_fRotation;
	float m_fSizeMult;
	float m_fOpacityMult;

	SRenderPostfilterPerScreenDecalParameters() = default;
	~SRenderPostfilterPerScreenDecalParameters() = default;
};
