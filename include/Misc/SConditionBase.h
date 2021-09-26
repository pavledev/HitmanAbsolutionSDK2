#pragma once

#include "ECompiledConditionType.h"
#include "ZBehaviorTreeVariable.h"

struct SConditionBase
{
	ECompiledConditionType eConditionType;
	unsigned int nConditionModifiers;
	ZBehaviorTreeVariable assignTo;

	SConditionBase() = default;
	~SConditionBase() = default;
};
