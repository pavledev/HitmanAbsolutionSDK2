#pragma once

#include "ECompiledConditionType.h"
#include "ZBehaviorTreeVariable.h"

class SConditionBase
{
public:
    ECompiledConditionType eConditionType;
    unsigned int nConditionModifiers;
    ZBehaviorTreeVariable assignTo;
};
