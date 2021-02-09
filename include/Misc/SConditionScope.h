#pragma once

#include "SBehaviorBase.h"
#include "TArrayRef.h"
#include "SConditionBase.h"

class SConditionScope : public SBehaviorBase
{
public:
    SBehaviorBase* pChild;
    SBehaviorBase* pSibling;
    TArrayRef<SConditionBase*> conditions;
};
