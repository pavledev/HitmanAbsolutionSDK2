#pragma once

#include "TArray.h"
#include "DifficultyLevelEnum.h"

class SRatingData
{
public:
    TArray<unsigned short> m_CheckpointStyles;
    TArray<bool> m_TitlesAchieved;
    TArray<bool> m_TitlesViewed;
    TArray<DifficultyLevelEnum> m_CPDifficulty;
    TArray<int> m_CPChallenges;
    int m_iLastUnlockedTitle;
};
