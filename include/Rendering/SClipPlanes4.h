#pragma once

#include "float4.h"

struct SClipPlanes4
{
	float4 x4;
	float4 y4;
	float4 z4;
	float4 w4;

	SClipPlanes4() = default;
	~SClipPlanes4() = default;
};
