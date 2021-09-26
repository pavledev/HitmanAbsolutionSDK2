#pragma once

#include "SFloat16.h"

struct SBindPoseQV
{
	SFloat16 rotation[4];
	SFloat16 translation[3];

	SBindPoseQV() = default;
	~SBindPoseQV() = default;
};
