#pragma once

#include "ZEntityImpl.h"
#include "TArray.h"
#include "ZString.h"

class IBoolCondition;
class ZComponentCreateInfo;
struct SBehaviorBase;
template <class T> class TEntityRef;

class __declspec(novtable) ZBehaviorEntityBase : public ZEntityImpl
{
public:
	TArray<TEntityRef<IBoolCondition>> m_conditions;
	ZString m_sMatch;

	~ZBehaviorEntityBase() override = default;
	virtual bool ContainsBehavior(SBehaviorBase* behaviorBase) = 0;

	static void RegisterType();
	ZBehaviorEntityBase(ZComponentCreateInfo& info);
	ZBehaviorEntityBase() = default;
	bool IsActive();
	const ZString& GetMatchName() const;
};
