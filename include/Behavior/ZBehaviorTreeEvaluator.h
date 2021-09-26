#pragma once

#include "TResourcePtr.h"
#include "SBehaviorTreeContext.h"
#include "TMaxArray.h"

class ZCompiledBehaviorTree;
struct SBehaviorTreeEvaluationLog;
struct SBehaviorBase;
struct SConditionBase;

class ZBehaviorTreeEvaluator
{
public:
	const TResourcePtr<ZCompiledBehaviorTree>& m_pTree;
	SBehaviorTreeContext& m_Context;
	const TMaxArray<SBehaviorBase*, 2>& m_CurrentBehaviors;
	SBehaviorTreeEvaluationLog* m_pLog;

	ZBehaviorTreeEvaluator() = default;
	ZBehaviorTreeEvaluator(const TResourcePtr<ZCompiledBehaviorTree>& pTree, SBehaviorTreeContext& context, const TMaxArray<SBehaviorBase*, 2>& currentBehaviors, SBehaviorTreeEvaluationLog* pLog);
	~ZBehaviorTreeEvaluator() = default;
	TMaxArray<SBehaviorBase*, 2> Evaluate();
	TMaxArray<SBehaviorBase*, 2> operator()();
	const TResourcePtr<ZCompiledBehaviorTree>& GetTree() const;
	SBehaviorTreeContext& Context();
	const TMaxArray<SBehaviorBase*, 2>& CurrentBehaviors();
	void Log(SConditionBase* pCondition, bool bResult);
	SBehaviorTreeEvaluationLog* GetLog() const;
};
