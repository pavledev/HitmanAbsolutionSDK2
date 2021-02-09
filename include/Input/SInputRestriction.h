#pragma once

#include "SVector3.h"

class alignas(4) SInputRestriction
{
public:
    bool m_bBlocked;
    bool m_bInput;
    float m_fBlockAngle;
    float m_fBlockRange;
    SVector3 m_vBlockingNormal;
    float m_fInputAngle;
    bool m_bExplicitNormal;
};
