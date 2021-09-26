#pragma once

#include "SVector3.h"

struct SGateDesc
{
	SVector3 vPortalOS[4];
	unsigned char nFlags;

	SGateDesc() = default;
	~SGateDesc() = default;
};
