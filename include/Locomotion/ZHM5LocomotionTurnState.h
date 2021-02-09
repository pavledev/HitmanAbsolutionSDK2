#pragma once

#include "ZHM5LocomotionState.h"
#include "ZHM5LocomotionTurnAnimDatabase.h"

class ZHM5LocomotionTurnState : public ZHM5LocomotionState
{
public:
    bool m_bExitTurn;
    float m_fRotationScale;
    float m_fFraction;
    float m_fTime;
    ZHM5LocomotionTurnAnimDatabase m_TurnAnimationDatabase;
    const STurnAnim* m_pTurnAnim;
};
