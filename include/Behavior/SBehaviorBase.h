#pragma once

#include "ECompiledBehaviorType.h"

struct SBehaviorBase
{
	ECompiledBehaviorType eBehaviorType;

	SBehaviorBase() = default;
	~SBehaviorBase() = default;
	bool IsCommand() const;
	bool IsBehavior() const;
	bool IsSequence() const;
};
