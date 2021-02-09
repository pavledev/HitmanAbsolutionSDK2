#pragma once

#include "TArray.h"
#include "SFullGoalData.h"

class SChallengeData
{
public:
    TArray<SFullGoalData> m_FullGoalProgess;
    int m_iLastUnlockedChallenge;
    int m_iNumChallengesCompleted;
};
