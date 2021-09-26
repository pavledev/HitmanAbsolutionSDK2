#pragma once

#include "TMap.h"

struct STypeID;

struct SEntityStats
{
	TMap<STypeID*, int> leafTypeMap;

	SEntityStats() = default;
	~SEntityStats() = default;
};
