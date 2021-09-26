#pragma once

#include "TArray.h"
#include "DifficultyLevelEnum.h"

struct SRatingData
{
	TArray<unsigned short> m_CheckpointStyles;
	TArray<bool> m_TitlesAchieved;
	TArray<bool> m_TitlesViewed;
	TArray<DifficultyLevelEnum> m_CPDifficulty;
	TArray<int> m_CPChallenges;
	int m_iLastUnlockedTitle;

	SRatingData(const SRatingData& other);
	SRatingData() = default;
	SRatingData& operator=(const SRatingData& other);
	unsigned short& GetValue(unsigned int nLevelIndex, unsigned int nCheckPoint, unsigned int nPlayStyle);
	void SetTitleAchieved(int titleIdx);
	bool IsTitleAchieved(int titleIdx) const;
	void SetTitleViewed(int nTitleIndex, bool bViewed);
	bool GetTitleViewed(int nTitleIndex) const;
	DifficultyLevelEnum& GetCPDifficulty(int lvl, int cp);
	int& GetCPChallenges(int lvl, int cp);
	~SRatingData() = default;
};
