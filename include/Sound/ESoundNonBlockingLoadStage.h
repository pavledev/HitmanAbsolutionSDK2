#pragma once

enum ESoundNonBlockingLoadStage
{
    ESoundNonBlockingLoadStage_Uninitialized = 0x0,
    ESoundNonBlockingLoadStage_OpeningResource = 0x1,
    ESoundNonBlockingLoadStage_ReadyForCreatingSound = 0x2,
    ESoundNonBlockingLoadStage_CreatingSound = 0x3,
    ESoundNonBlockingLoadStage_GettingSubSound = 0x4,
    ESoundNonBlockingLoadStage_Succeeded = 0x5,
    ESoundNonBlockingLoadStage_Failed = 0x6
};
