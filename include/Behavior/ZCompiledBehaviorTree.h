#pragma once

#include "SConditionScope.h"
#include "ZString.h"
#include "EBehaviorReturnCode.h"
#include "TMaxArray.h"
#include "TArrayRef.h"

class ZActiveBehavior;
class ZBehaviorEntityBase;
class ZBehaviorTreeEvaluator;
struct SBehaviorBase;
struct SBehaviorTreeContext;
struct SConditionBase;
template <class T> class TEntityRef;

class ZCompiledBehaviorTree
{
public:
	struct SInitializationResult
	{
		union
		{
			ZActiveBehavior* m_pSelectedBehavior;
			EBehaviorReturnCode m_eCommandResult;
		};

		enum
		{
			T_BEHAVIOR = 0,
			T_COMMAND = 1
		} m_type;

		SInitializationResult(EBehaviorReturnCode eCommandResult);
		SInitializationResult(ZActiveBehavior* pSelectedBehavior);
		ZActiveBehavior* GetSelectedBehavior() const;
		EBehaviorReturnCode GetCommandResult() const;
	};

	SConditionScope m_root;
	SBehaviorBase* m_pEnd;
	TArrayRef<ZString> m_sceneReferenceNames;

	bool Contains(SBehaviorBase* pBehavior) const;
	static SInitializationResult InitializeBehavior(SBehaviorBase* pBehavior, const SBehaviorTreeContext& context);
	static ZString GetBehaviorName(SBehaviorBase* pBehavior);
	static ZString GetConditionName(SConditionBase* pCondition);
	TMaxArray<SBehaviorBase*, 2> Evaluate(ZBehaviorTreeEvaluator& evaluator);
	bool CheckAbortConditions(ZBehaviorTreeEvaluator& evaluator, SBehaviorBase* pScope, TEntityRef<ZBehaviorEntityBase> pThroughNode) const;
	bool EvaluateMatch(ZBehaviorTreeEvaluator& evaluator, TEntityRef<ZBehaviorEntityBase> pBehavior, bool& bAbort) const;
	ZCompiledBehaviorTree() = default;
	~ZCompiledBehaviorTree() = default;
};
