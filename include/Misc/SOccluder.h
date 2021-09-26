#pragma once

#include "SVector3.h"
#include "SVector2.h"

struct SOccluder
{
	SVector3 vCenter;
	SVector3 vUp;
	SVector3 vNormal;
	SVector2 vSize;
	bool bOneSided;
	bool bFlipNormal;

	SOccluder() = default;
	~SOccluder() = default;
};
