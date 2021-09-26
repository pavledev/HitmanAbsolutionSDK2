#pragma once

#include "ELevelIndex.h"

struct SContractUnlockStatus
{
	bool bUnlocked;
	ELevelIndex eLevelIndex;
	int iContractIndex;

	SContractUnlockStatus() = default;
	~SContractUnlockStatus() = default;
};
