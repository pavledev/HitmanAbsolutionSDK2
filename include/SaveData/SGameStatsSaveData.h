#pragma once

#include "SGameStatsData.h"

struct SGameStatsSaveData
{
	SGameStatsData m_Data;
	int m_iPreciseSniperKillCount;

	SGameStatsSaveData(const SGameStatsSaveData& __that);
	SGameStatsSaveData() = default;
	~SGameStatsSaveData() = default;
	SGameStatsSaveData& operator=(const SGameStatsSaveData& __that);
};
