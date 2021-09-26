#pragma once

#include "IComponentInterface.h"
#include "ZEvent.h"
#include "TEntityRef.h"

class ZEventNull;

class __declspec(novtable) IBoolCondition : public IComponentInterface
{
public:
	~IBoolCondition() override = default;
	virtual bool GetBoolConditionValue() = 0;
	virtual ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull>& GetBoolConditionChangedEvent() = 0;

	static void RegisterType();
	IBoolCondition() = default;
};
