#pragma once

#include "ZHM5ValueEntity_Base.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZVariant.h"
#include "ZVariantRef.h"

class ZHM5ValueReceiver_float32;
class ZComponentCreateInfo;
struct STypeID;

class ZHM5ValueEntity_float32 : public ZHM5ValueEntity_Base
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_Value;
	TArray<ZHM5ValueReceiver_float32*> m_ReceiverList;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5ValueEntity_float32() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void FirePin() override;
	void SendValueToReceivers() override;

	ZVariant GetValue() override;

	ZHM5ValueEntity_float32() = default;
	static void RegisterType();
	ZHM5ValueEntity_float32(ZComponentCreateInfo& Info);
	float GetFloatValue();
	void OnSet(const float& value);
	void OnGet();
	void OnValueChanged();
	void RegisterReceiver(ZHM5ValueReceiver_float32* pReceiver);
	void UnregisterReceiver(ZHM5ValueReceiver_float32* pReceiver);
};
