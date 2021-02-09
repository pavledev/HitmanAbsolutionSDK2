#pragma once

#include "ZHM5LocomotionState.h"
#include "SIdleAnimType.h"

class alignas(8) ZHM5LocomotionIdleState : public ZHM5LocomotionState
{
    bool m_bPlayIdleAnims;
    float m_fIdleTime;
    int m_nIdleAnimIndex;
    SIdleAnimType m_aIdleAnimInfo[7];
};
