#pragma once

#include "ELevelIndex.h"
#include "TArray.h"

struct SCheckpointSaveData;

struct SLevelSaveData
{
	ELevelIndex m_LevelID;
	TArray<SCheckpointSaveData> m_CheckpointData;

	SLevelSaveData(const SLevelSaveData& __that);
	SLevelSaveData(ELevelIndex eIndex);
	SLevelSaveData() = default;
	~SLevelSaveData() = default;
	SLevelSaveData& operator=(const SLevelSaveData& __that);
};
