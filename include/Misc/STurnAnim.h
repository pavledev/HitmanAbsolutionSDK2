#pragma once

#include "ETurnAnimType.h"

struct alignas(4) STurnAnim
{
    unsigned int m_nNodeID;
    float m_fRotation;
    ETurnAnimType m_eTurnAnimType;
    bool m_bRightLeg;
    bool m_bHalfStep;
};
