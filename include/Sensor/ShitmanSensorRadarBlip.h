#pragma once

#include "ZHM5IndicatorManager.h"
#include "EIndicatorType.h"

class ShitmanSensorRadarBlip
{
public:
    EIndicatorType m_eIndicator;
    bool m_bHMInSight;
    float m_fDistanceToHM;
    TEntityRef<ZActor> m_rActor;
};
