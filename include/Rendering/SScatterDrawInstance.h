#pragma once

#include "float4.h"
#include "SMatrix.h"

struct SScatterDrawInstance
{
	SMatrix m_mMatrix;
	float4 m_vDisruptorPosition;
	float4 m_vBendDirection;

	SScatterDrawInstance() = default;
	~SScatterDrawInstance() = default;
};
