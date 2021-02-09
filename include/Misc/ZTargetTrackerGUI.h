#pragma once

#include "IGameStatsListener.h"
#include "ZTargetTracker.h"
#include "ZStopWatchEntity.h"

class alignas(8) ZTargetTrackerGUI : public IGameStatsListener
{
public:
    ZTargetTracker* m_pTargetTracker;
    ZGameTime m_tLastTimerUpdate;
    ZGameTime m_tTargetUpdateDelay;
    bool m_bUpdate;
    bool m_bInitCalled;
    bool m_bTimerInitCalled;
    TEntityRef<ZStopWatchEntity> m_pTimer;
};
