#pragma once

#include "TFixedArray.h"
#include "TArray.h"
#include "STechniqueUnlockState.h"

struct STechniquesSaveData
{
	TFixedArray<unsigned char, 10> m_iTechniqueUnlockedLevel;
	TArray<STechniqueUnlockState> m_aUnlockState;
	TArray<bool> m_aViewedState;
	STechniqueUnlockState m_LastUnlockedTechnique;

	STechniquesSaveData(const STechniquesSaveData& __that);
	STechniquesSaveData() = default;
	~STechniquesSaveData() = default;
	STechniquesSaveData& operator=(const STechniquesSaveData& __that);
};
