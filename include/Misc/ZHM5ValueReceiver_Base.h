#pragma once

#include "ZEntityImpl.h"
#include "IValueEntity.h"

class __declspec(novtable) ZHM5ValueReceiver_Base : public ZEntityImpl, public IValueEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	static SComponentMapEntry s_componentMap[0];

	~ZHM5ValueReceiver_Base() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	virtual void OnGet() = 0;

	virtual ZVariant GetValue() = 0;

	ZHM5ValueReceiver_Base() = default;
	static void RegisterType();
	ZHM5ValueReceiver_Base(ZComponentCreateInfo& Info);
};
