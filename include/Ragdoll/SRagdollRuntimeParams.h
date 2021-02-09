#pragma once

#include "ECCDUsage.h"
#include "ECollisionPriority.h"

class SRagdollRuntimeParams
{
public:
    bool m_bCreateTargetDummies;
    ECCDUsage m_eCCDUsage;
    ECollisionPriority m_eSolverPriority;
    float m_fRagdollScale;
};
