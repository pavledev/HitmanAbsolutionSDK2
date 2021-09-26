#pragma once

#include "float4.h"

struct SOccluderPlaneStateSoA
{
	float4 OccluderPlanes[40];
	unsigned int nNumPerOccluders[8];
	unsigned int nNumOccluders;

	SOccluderPlaneStateSoA() = default;
	~SOccluderPlaneStateSoA() = default;
};
