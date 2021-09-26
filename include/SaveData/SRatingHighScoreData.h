#pragma once

#include "TArray.h"

struct SRatingHighScoreData
{
	TArray<unsigned int> m_HighScores;
	TArray<signed char> m_HighTitles;

	SRatingHighScoreData(const SRatingHighScoreData& __that);
	SRatingHighScoreData() = default;
	unsigned int& GetHighScore(unsigned int nLevelIndex, unsigned int nCheckPoint, int difficultyLevel);
	int GetMaxHighScore(unsigned int nLevelIndex, unsigned int nCheckPoint);
	char& GetHighTitle(unsigned int nLevelIndex, unsigned int nCheckPoint, int difficultyLevel);
	char GetMaxHighTitle(unsigned int nLevelIndex, unsigned int nCheckPoint);
	~SRatingHighScoreData() = default;
	SRatingHighScoreData& operator=(const SRatingHighScoreData& __that);
};
