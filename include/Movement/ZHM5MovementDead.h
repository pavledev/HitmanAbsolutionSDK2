#pragma once

#include "ZHM5BaseMovement.h"
#include "SHitInfo.h"

class alignas(16) ZHM5MovementDead : public ZHM5BaseMovement
{
    SHitInfo m_HitInfo;
    ZGameTime m_startOfDeath;
    bool m_bTimeOut;
};
