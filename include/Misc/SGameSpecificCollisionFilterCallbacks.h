#pragma once

#include "ZString.h"

class ZFilterGroupMask;

struct SGameSpecificCollisionFilterCallbacks
{
	bool (*m_fpGetRayLayerFilterGroupMask)(const unsigned int param1, ZFilterGroupMask& filterGroupMask);
	bool (*m_fpIsCollisionLayerOpaque)(const unsigned short param1);
	ZString (*m_fpGetLevelAndCheckpointName)();

	SGameSpecificCollisionFilterCallbacks() = default;
	~SGameSpecificCollisionFilterCallbacks() = default;
};
