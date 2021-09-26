#pragma once

#include "ZGridNodeRef.h"

struct SFindBestTacticalPositionOutput
{
	ZGridNodeRef m_node;
	float m_fRating;
	bool m_bValid;

	SFindBestTacticalPositionOutput(const SFindBestTacticalPositionOutput& __that);
	SFindBestTacticalPositionOutput() = default;
	~SFindBestTacticalPositionOutput() = default;
	SFindBestTacticalPositionOutput& operator=(const SFindBestTacticalPositionOutput& __that);
};
