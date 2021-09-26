#pragma once

#include "SConditionBase.h"

struct SBehaviorTreeContext;

struct SCondition_Cooldown : SConditionBase
{
	float fCooldown;

	bool Eval(SBehaviorTreeContext& context) const;
	SCondition_Cooldown() = default;
	~SCondition_Cooldown() = default;
};
