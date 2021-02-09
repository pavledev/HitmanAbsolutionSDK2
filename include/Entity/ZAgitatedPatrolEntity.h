#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZAgitatedWaypointEntity.h"
#include "DifficultyLevelEnum.h"

class ZAgitatedPatrolEntity : public ZEntityImpl
{
public:
    TArray<TEntityRef<ZAgitatedWaypointEntity>> m_waypoints;
    bool m_bEnabled;
    DifficultyLevelEnum m_eMinDifficulty;
    unsigned int m_nMaxNumberOfGuards;
};
