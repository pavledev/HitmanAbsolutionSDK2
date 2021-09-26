#pragma once

struct SBehaviorTreeEvaluationLogEntry
{
	unsigned int m_nBehaviorTreeIndex;
	unsigned int m_nConditionOffset;
	bool m_bResult;

	SBehaviorTreeEvaluationLogEntry() = default;
	~SBehaviorTreeEvaluationLogEntry() = default;
};
