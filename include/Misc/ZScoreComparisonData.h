#pragma once

#include "ZString.h"

class ZScoreComparisonData
{
public:
	ZString m_sFriendName;
	int m_iFriendScore;
	int m_iCountryAverage;
	int m_iWorldAverage;

	ZScoreComparisonData(const ZScoreComparisonData& __that);
	ZScoreComparisonData() = default;
	~ZScoreComparisonData() = default;
};
