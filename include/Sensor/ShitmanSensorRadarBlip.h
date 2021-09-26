#pragma once

#include "ZHM5IndicatorManager.h"
#include "TEntityRef.h"

class ZActor;

struct ShitmanSensorRadarBlip
{
	ZHM5IndicatorManager::EIndicatorType m_eIndicator;
	bool m_bHMInSight;
	float m_fDistanceToHM;
	TEntityRef<ZActor> m_rActor;

	ShitmanSensorRadarBlip(const ShitmanSensorRadarBlip& __that);
	ShitmanSensorRadarBlip() = default;
	~ShitmanSensorRadarBlip() = default;
};
