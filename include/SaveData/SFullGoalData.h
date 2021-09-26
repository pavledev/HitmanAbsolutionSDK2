#pragma once

#include "ELevelIndex.h"
#include "EUIText.h"
#include "TArray.h"

struct SSubGoalProgressData;

struct SFullGoalData
{
	ELevelIndex m_eLevelIndex;
	int m_nID;
	EUIText m_eMessageText;
	EUIText m_eFriendMessageText;
	long long m_nTimestamp;
	int m_nCategory;
	bool m_bHasBeenSent;
	bool m_bIsSecurityTapeChallenge;
	bool m_bTracked;
	bool m_bCompleted;
	bool m_bHidden;
	bool m_bLocked;
	TArray<SSubGoalProgressData> m_SubgoalProgress;

	SFullGoalData(const SFullGoalData& __that);
	SFullGoalData() = default;
	~SFullGoalData() = default;
	SFullGoalData& operator=(const SFullGoalData& __that);
};
