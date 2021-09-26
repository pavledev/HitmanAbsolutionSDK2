#pragma once

#include "ZHM5ValueReceiver_Base.h"
#include "IBoolCondition.h"
#include "ZHM5ValueEntity_bool.h"

class ZHM5ValueReceiver_bool : public ZHM5ValueReceiver_Base, public IBoolCondition
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<ZHM5ValueEntity_bool> m_ValueEntity;
	ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull> m_ChangedEvent;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5ValueReceiver_bool() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void OnGet() override;

	ZVariant GetValue() override;

	bool GetBoolConditionValue() override;
	ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull>& GetBoolConditionChangedEvent() override;

	ZHM5ValueReceiver_bool() = default;
	static void RegisterType();
	ZHM5ValueReceiver_bool(ZComponentCreateInfo& Info);
	void ReceiveValue(bool bValue);
};
