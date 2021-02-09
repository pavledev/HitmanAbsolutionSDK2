#pragma once

#include "EIndicatorType.h"
#include "EIndicatorHeight.h"

struct alignas(4) SHudIndicator
{
public:
    float fDistance;
    float fDegrees;
    float fFacingDirection;
    EIndicatorType m_eIndicatorType;
    EIndicatorHeight m_eIndicatorHeight;
    __int8 m_bVisibleToHitman : 1;
    __int8 m_bDisplay : 1;
};
