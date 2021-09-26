#pragma once

#include "TArray.h"
#include "ZResourceID.h"
#include "SBehaviorTreeEvaluationLogEntry.h"
#include "TResourcePtr.h"
#include "ZCompiledBehaviorTree.h"

class ZCompiledBehaviorTree;

struct SBehaviorTreeEvaluationLog
{
	TArray<ZResourceID> m_BehaviorTrees;
	TArray<SBehaviorTreeEvaluationLogEntry> m_Entries;

	void Log(const TResourcePtr<ZCompiledBehaviorTree>& pTree, SConditionBase* pCondition, bool bResult);
	SBehaviorTreeEvaluationLog(const SBehaviorTreeEvaluationLog& __that);
	SBehaviorTreeEvaluationLog() = default;
	~SBehaviorTreeEvaluationLog() = default;
	SBehaviorTreeEvaluationLog& operator=(const SBehaviorTreeEvaluationLog& __that);
};
