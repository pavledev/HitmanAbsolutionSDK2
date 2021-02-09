#pragma once

#include "ELevelIndex.h"
#include "TArray.h"
#include "SCPProgressionState.h"

class SLevelCPProgressionData
{
public:
    ELevelIndex m_eLevelIndex;
    TArray<SCPProgressionState> m_aCPStates;
};
