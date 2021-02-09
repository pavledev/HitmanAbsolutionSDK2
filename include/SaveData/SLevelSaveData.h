#pragma once

#include "ELevelIndex.h"
#include "TArray.h"
#include "SCheckpointSaveData.h"

class SLevelSaveData
{
public:
    ELevelIndex m_LevelID;
    TArray<SCheckpointSaveData> m_CheckpointData;
};
