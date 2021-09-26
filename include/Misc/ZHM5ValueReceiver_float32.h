#pragma once

#include "ZHM5ValueReceiver_Base.h"
#include "TEntityRef.h"

class ZHM5ValueReceiver_float32 : public ZHM5ValueReceiver_Base
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<ZHM5ValueEntity_float32> m_ValueEntity;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5ValueReceiver_float32() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void OnGet() override;

	ZVariant GetValue() override;

	ZHM5ValueReceiver_float32() = default;
	static void RegisterType();
	ZHM5ValueReceiver_float32(ZComponentCreateInfo& Info);
	void ReceiveValue(float val);
};
