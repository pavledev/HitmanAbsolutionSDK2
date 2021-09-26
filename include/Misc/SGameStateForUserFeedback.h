#pragma once

#include "EGameFlagForUserFeedback.h"

struct SGameStateForUserFeedback
{
	unsigned long long m_iGameState;

	SGameStateForUserFeedback() = default;
	~SGameStateForUserFeedback() = default;
	bool QueryFlag(const EGameFlagForUserFeedback& eQuery) const;
	void SetFlag(EGameFlagForUserFeedback eFlag);
	void ResetFlag(EGameFlagForUserFeedback flagToReset);
	void Reset();
};
