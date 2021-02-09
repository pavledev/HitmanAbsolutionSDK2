#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "IBoolCondition.h"

class ZIllegalActionEntity : public ZEntityImpl
{
public:
    bool m_bIsIllegal;
    float m_fDuration;
    TEntityRef<IBoolCondition> m_pEnabledCondition;
    TEntityRef<IBoolCondition> m_pOutfitCondition;
};
