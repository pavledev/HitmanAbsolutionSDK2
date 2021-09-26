#pragma once

#include "SQV.h"

struct sLedgeFeetLockInfo
{
	bool m_bLockFeet;
	bool m_bStoreFeetInfo;
	SQV m_qvLeftFeet;
	SQV m_qvRightFeet;
	SQV m_qvNewPelvis;
	SQV m_qvResults[7];
	float m_fWeight;
	float m_fTargetWeight;

	sLedgeFeetLockInfo() = default;
	~sLedgeFeetLockInfo() = default;
	void Reset();
};
