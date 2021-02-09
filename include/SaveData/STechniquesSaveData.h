#pragma once

#include "TFixedArray.h"
#include "TArray.h"
#include "STechniqueUnlockState.h"

class STechniquesSaveData
{
public:
    TFixedArray<unsigned char, 10> m_iTechniqueUnlockedLevel;
    TArray<STechniqueUnlockState> m_aUnlockState;
    TArray<bool> m_aViewedState;
    STechniqueUnlockState m_LastUnlockedTechnique;
};
