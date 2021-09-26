#pragma once

#include "ELevelIndex.h"

struct SLevelProgressionData
{
	ELevelIndex m_eLevelIndex;
	int m_nCheckpointIndex;
	int m_nDifficulty;

	SLevelProgressionData() = default;
	~SLevelProgressionData() = default;
	bool HaveProgress() const;
};
