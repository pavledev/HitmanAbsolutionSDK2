#pragma once

#include "ZDelegate.h"
#include "TArray.h"
#include "ZLeaderboardEntry.h"
#include "ZScoreComparisonData.h"

class alignas(8) ZLeaderboard
{
public:
    unsigned int m_iPendingUploadScoreId;
    unsigned int m_iPendingGetScoresId;
    unsigned int m_iPendingGetScoresFilter;
    ZDelegate<void __cdecl(bool, int, TArray<ZLeaderboardEntry> const&, int)> m_fnGetScoresCallback;
    ZDelegate<void __cdecl(bool, int)> m_fnUploadScoreCallback;
    unsigned int m_iPendingGetAverageScoresId;
    ZDelegate<void __cdecl(bool, TArray<int> const&)> m_fnGetAverageScoresCallback;
    unsigned int m_iPendingGetScoreComparisonId;
    ZDelegate<void __cdecl(bool, ZScoreComparisonData const&)> m_fnGetScoreComparisonCallback;
    int m_iType;
};
