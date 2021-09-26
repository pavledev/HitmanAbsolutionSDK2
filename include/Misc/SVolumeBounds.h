#pragma once

#include "SQV.h"
#include "SVector3.h"

struct SVolumeBounds
{
	SQV mTransform;
	SVector3 vCenter;
	SVector3 vHalfSize;

	SVolumeBounds() = default;
	~SVolumeBounds() = default;
};
