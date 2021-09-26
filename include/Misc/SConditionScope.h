#pragma once

#include "SBehaviorBase.h"
#include "TArrayRef.h"

class ZBehaviorTreeEvaluator;
struct SBehaviorTreeContext;
struct SConditionBase;

struct SConditionScope : SBehaviorBase
{
	SBehaviorBase* pChild;
	SBehaviorBase* pSibling;
	TArrayRef<SConditionBase*> conditions;

	bool EvaluateConditions(ZBehaviorTreeEvaluator& evaluator, bool& bAbort);
	static bool EvaluateCondition(const SConditionBase* pCondition, SBehaviorTreeContext& context);
	static bool EvaluateConditionWithModifiers(const SConditionBase* pCondition, SBehaviorTreeContext& context, bool& bAbort);
	bool Contains(const SBehaviorBase* pBehavior) const;
	SConditionScope() = default;
	~SConditionScope() = default;
};
