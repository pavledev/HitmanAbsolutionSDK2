#pragma once

#include "EDynamicVariableType.h"
#include "TMaxArray.h"
#include "TEntityRef.h"
#include "TRefCountPtrArg.h"
#include "TRefCountPtr.h"

class ZKnowledge;
struct SKnownEntity;
class ZActor;
class ZBehaviorTreeVariable;

struct SBehaviorTreeContext
{
	enum
	{
		MAX_NUM_VARIABLES = 64
	};

	ZKnowledge* m_pKnowledge;
	TMaxArray<TRefCountPtr<SKnownEntity>, 16> m_variables[192];

	TRefCountPtrArg<SKnownEntity> Get(ZBehaviorTreeVariable variable) const;
	void Set(ZBehaviorTreeVariable variable, const TRefCountPtr<SKnownEntity>& value);
	const TMaxArray<TRefCountPtr<SKnownEntity>, 16>& GetList(ZBehaviorTreeVariable variable) const;
	void SetList(ZBehaviorTreeVariable variable, const TMaxArray<TRefCountPtr<SKnownEntity>, 16>& list);
	ZKnowledge& Knowledge() const;
	TEntityRef<ZActor> Actor() const;
	SBehaviorTreeContext(const SBehaviorTreeContext& base);
	SBehaviorTreeContext(ZKnowledge* pKnowledge);
	SBehaviorTreeContext() = default;
	SBehaviorTreeContext& operator=(const SBehaviorTreeContext& other);
	void Clear();
	unsigned int GetVariableIndex(ZBehaviorTreeVariable variable) const;
	void SetDynamic(EDynamicVariableType var, const TRefCountPtr<SKnownEntity>& ref);
	void SetDynamicList(EDynamicVariableType var, const TMaxArray<TRefCountPtr<SKnownEntity>, 16>& list);
	~SBehaviorTreeContext() = default;
};
