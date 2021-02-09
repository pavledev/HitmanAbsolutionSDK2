#pragma once

#include "SGameStatsData.h"

class alignas(8) SGameStatsSaveData
{
public:
    SGameStatsData m_Data;
    int m_iPreciseSniperKillCount;
};
