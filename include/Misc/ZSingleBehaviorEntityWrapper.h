#pragma once

#include "ZBehaviorEntityBase.h"

class ZSingleBehaviorEntityWrapper : public ZBehaviorEntityBase
{
public:
	SBehaviorBase* m_pBehavior;

	~ZSingleBehaviorEntityWrapper() override = default;
	bool ContainsBehavior(SBehaviorBase* pBehavior) override;

	static void RegisterType();
	ZSingleBehaviorEntityWrapper(ZComponentCreateInfo& info, SBehaviorBase* pBehavior);
	ZSingleBehaviorEntityWrapper() = default;
	SBehaviorBase* GetCompiledBehavior();
};
