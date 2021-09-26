#pragma once

enum ESoundAmbienceOperation
{
	eSoundAmbienceOperation_ClearParameters = 0,
	eSoundAmbienceOperation_IncrementAddCount = 1,
	eSoundAmbienceOperation_AddDynamicParameters = 2,
	eSoundAmbienceOperation_ApplyDynamicParameters = 3,
	eSoundAmbienceOperation_TagForPlay = 4,
	eSoundAmbienceOperation_TagAsCurrent = 5,
	eSoundAmbienceOperation_UnTagAsCurrent = 6,
	eSoundAmbienceOperation_TagForStop = 7,
	eSoundAmbienceOperation_Pause = 8,
	eSoundAmbienceOperation_UpdatePlayState = 9,
	eSoundAmbienceOperation_StorePlayState = 10,
	eSoundAmbienceOperation_RestorePlayState = 11,
	eSoundAmbienceOperation_SetGamePaused = 12,
	eSoundAmbienceOperation_SetGameUnpaused = 13
};
