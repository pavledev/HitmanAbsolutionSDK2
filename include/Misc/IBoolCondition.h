#pragma once

#include "IComponentInterface.h"
#include "ZEvent.h"
#include "TEntityRef.h"

class IBoolCondition : IComponentInterface
{
public:
    virtual bool GetBoolConditionValue();
    virtual ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull>* GetBoolConditionChangedEvent();
};
