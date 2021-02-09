#pragma once

#include "ZString.h"

class alignas(4) ZLeaderboardEntry
{
public:
    int m_iRank;
    ZString m_sUserId;
    ZString m_sDisplayName;
    int m_iScore;
    int m_iRating;
    bool m_bValid;
};
