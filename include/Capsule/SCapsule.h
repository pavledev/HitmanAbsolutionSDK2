#pragma once

#include "float4.h"

struct SCapsule
{
	float4 m_vBottom;
	float4 m_vTop;
	float m_fRadius;

	SCapsule(const float4& vBottom, const float4& vTop, const float fRadius);
	SCapsule() = default;
	~SCapsule() = default;
};
