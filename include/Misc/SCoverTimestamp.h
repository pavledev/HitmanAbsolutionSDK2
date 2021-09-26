#pragma once

#include "ZGameTime.h"

class ZHM5CoverPlane;

struct SCoverTimestamp
{
	ZHM5CoverPlane* pPlane;
	ZGameTime tLastUpdate;
	bool bHasLOF;

	bool operator<(const SCoverTimestamp& s0);
	SCoverTimestamp(const SCoverTimestamp& __that);
	SCoverTimestamp() = default;
	~SCoverTimestamp() = default;
	SCoverTimestamp& operator=(const SCoverTimestamp& __that);
};
