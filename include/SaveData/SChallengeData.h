#pragma once

#include "TArray.h"

struct SFullGoalData;

struct SChallengeData
{
	TArray<SFullGoalData> m_FullGoalProgess;
	int m_iLastUnlockedChallenge;
	int m_iNumChallengesCompleted;

	SChallengeData(const SChallengeData& __that);
	SChallengeData() = default;
	~SChallengeData() = default;
	SChallengeData& operator=(const SChallengeData& __that);
};
