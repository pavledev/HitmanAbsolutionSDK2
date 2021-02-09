#pragma once

#include "TArray.h"
#include "SContractUnlockStatus.h"

class SContractSaveData
{
public:
    bool bTutorialPlayed;
    TArray<SContractUnlockStatus> aLocalContractUnlockStatusData;
};
