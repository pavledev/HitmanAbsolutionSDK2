#pragma once

#include "float4.h"
#include "ECollidablesType.h"

struct SSphereSweepInput
{
	float4 m_vFrom;
	float4 m_vTo;
	float m_fRadius;
	unsigned int m_nFilter;
	ECollidablesType m_eType;

	SSphereSweepInput() = default;
	~SSphereSweepInput() = default;
};
