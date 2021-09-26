#pragma once

#include "SQV.h"

struct sFeetInfo
{
	bool m_bUpdated;
	SQV m_FeetMatPos[2];

	sFeetInfo() = default;
	~sFeetInfo() = default;
};
