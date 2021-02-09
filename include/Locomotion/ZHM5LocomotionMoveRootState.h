#pragma once

#include "ZHM5LocomotionState.h"
#include "ZMapPoly.h"

class alignas(8) ZHM5LocomotionMoveRootState : public ZHM5LocomotionState
{
public:
    float m_fAnimRotation;
    float m_fAnimRotationDelta;
    float m_fAnimRotationLeft;
    float m_fStickBlendIn;
    float m_fBlendOutTime;
    float m_fBlendOutDuration;
    float m_fBlendOutAngle;
    float m_fQueuedTurnAngle;
    ZMapPoly m_MapBlendOutAngle;
    bool m_bTurnQueued;
    bool m_bExitTurn;
};
