#pragma once

#include "SVector3.h"

class alignas(4) SBaseMovmentCollisionInfo
{
public:
    bool m_bBlocked;
    SVector3 m_vBlockingNormal;
    bool m_bExplicitBlockingNormal;
    bool m_bReleaseBlock;
};
