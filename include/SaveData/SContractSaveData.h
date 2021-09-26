#pragma once

#include "TArray.h"

struct SContractUnlockStatus;

struct SContractSaveData
{
	bool bTutorialPlayed;
	TArray<SContractUnlockStatus> aLocalContractUnlockStatusData;

	SContractSaveData(const SContractSaveData& __that);
	SContractSaveData() = default;
	~SContractSaveData() = default;
	SContractSaveData& operator=(const SContractSaveData& __that);
};
