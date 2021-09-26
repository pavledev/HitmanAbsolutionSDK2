#pragma once

#include "ELevelIndex.h"
#include "TArray.h"

struct SCPProgressionState;

struct SLevelCPProgressionData
{
	ELevelIndex m_eLevelIndex;
	TArray<SCPProgressionState> m_aCPStates;

	SLevelCPProgressionData(const SLevelCPProgressionData& __that);
	SLevelCPProgressionData() = default;
	~SLevelCPProgressionData() = default;
	SLevelCPProgressionData& operator=(const SLevelCPProgressionData& __that);
};
