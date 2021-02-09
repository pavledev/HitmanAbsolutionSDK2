#pragma once

#include "ZHM5ValueReceiver_Base.h"
#include "IBoolCondition.h"
#include "ZHM5ValueEntity_bool.h"

class ZHM5ValueReceiver_bool : public ZHM5ValueReceiver_Base, public IBoolCondition
{
public:
    TEntityRef<ZHM5ValueEntity_bool> m_ValueEntity;
    ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull> m_ChangedEvent;
};
