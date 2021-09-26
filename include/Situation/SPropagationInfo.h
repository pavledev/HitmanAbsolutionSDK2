#pragma once

#include "ESituationType.h"

struct SPropagationInfo
{
	float m_fMinProximityDistance;
	float m_fMaxProximityDistance;
	float m_fMinLOSDistance;
	float m_fMaxLOSDistance;
	float m_fTargetDistance;
	float m_fProximitySpreadPerSecond;
	float m_fLOSSpreadPerSecond;
	float m_fMinJoinedTime;
	ESituationType m_eMaxPrioritySituation;

	SPropagationInfo() = default;
	~SPropagationInfo() = default;
};
