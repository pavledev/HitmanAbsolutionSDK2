#pragma once

#include "EActorAnimationOrder.h"
#include "ZPositionTarget.h"

class alignas(4) SOrderParamsBase
{
public:
    EActorAnimationOrder m_type;
    ZPositionTarget m_aimTarget;
    ZPositionTarget m_lookTarget;
    ZPositionTarget m_facingTarget;
    bool m_bFastStart;

    virtual ~SOrderParamsBase();
};
