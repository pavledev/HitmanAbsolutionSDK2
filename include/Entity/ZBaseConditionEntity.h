#pragma once

#include "ZEntityImpl.h"
#include "IBoolCondition.h"

class alignas(4) ZBaseConditionEntity : public ZEntityImpl, public IBoolCondition
{
public:
    ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull> m_ChangedEvent;
    bool m_bConditionValue;
    bool m_bIsActive;
};
