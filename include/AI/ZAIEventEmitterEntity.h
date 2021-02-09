#pragma once

#include "ZGameStatsEntityBase.h"
#include "ZAIGameState.h"

class ZAIEventEmitterEntity : public ZGameStatsEntityBase
{
public:
    float m_AlertableActorOnScreenCooldown;
    float m_AlertableGuardOnScreenCooldown;

    virtual void SendSignals(const ZAIGameState*, const ZAIGameState*);
};
