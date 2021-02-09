#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "IBoolCondition.h"
#include "SBehaviorBase.h"

class ZBehaviorEntityBase : public ZEntityImpl
{
public:
    TArray<TEntityRef<IBoolCondition>> m_conditions;
    ZString m_sMatch;

    virtual bool ContainsBehavior(SBehaviorBase*);
};
