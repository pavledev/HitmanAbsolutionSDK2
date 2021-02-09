#pragma once

#include "ELevelIndex.h"
#include "EUIText.h"
#include "TArray.h"
#include "SSubGoalProgressData.h"

class SFullGoalData
{
public:
    ELevelIndex m_eLevelIndex;
    int m_nID;
    EUIText m_eMessageText;
    EUIText m_eFriendMessageText;
    __int64 m_nTimestamp;
    int m_nCategory;
    bool m_bHasBeenSent;
    bool m_bIsSecurityTapeChallenge;
    bool m_bTracked;
    bool m_bCompleted;
    bool m_bHidden;
    bool m_bLocked;
    TArray<SSubGoalProgressData> m_SubgoalProgress;
};
