#pragma once

#include "EMoveSpeed.h"

struct SMoveSpeedConfiguration
{
	float m_distanceThresholdAtSpeed[4];

	SMoveSpeedConfiguration() = default;
	~SMoveSpeedConfiguration() = default;
	void SetSpeedForDistance(float fDistance, EMoveSpeed speed);
	bool GetSpeedForDistance(float fDistance, EMoveSpeed& speed);
};
