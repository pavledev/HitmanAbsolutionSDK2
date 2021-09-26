#pragma once

enum ESoundNonBlockingLoadStage
{
	ESoundNonBlockingLoadStage_Uninitialized = 0,
	ESoundNonBlockingLoadStage_OpeningResource = 1,
	ESoundNonBlockingLoadStage_ReadyForCreatingSound = 2,
	ESoundNonBlockingLoadStage_CreatingSound = 3,
	ESoundNonBlockingLoadStage_GettingSubSound = 4,
	ESoundNonBlockingLoadStage_Succeeded = 5,
	ESoundNonBlockingLoadStage_Failed = 6
};
