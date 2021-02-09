#pragma once

#include "ZHM5LocomotionState.h"

class alignas(8) ZHM5LocomotionStrafeRootState : public ZHM5LocomotionState
{
public:
    float m_fDeltaCamAngle;
};
