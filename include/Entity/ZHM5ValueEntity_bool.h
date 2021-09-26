#pragma once

#include "ZEntityImpl.h"
#include "IBoolCondition.h"
#include "IValueEntity.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZEvent.h"
#include "ZVariant.h"
#include "ZVariantRef.h"

class ZHM5ValueReceiver_bool;
class ZComponentCreateInfo;
class ZEventNull;
class ZString;
struct STypeID;
template <class T> class TEntityRef;

class ZHM5ValueEntity_bool : public ZEntityImpl, public IBoolCondition, public IValueEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EForwardRule
	{
		eAlways = 0,
		eValueChanged = 1
	};

	bool m_Value;
	bool m_bForwardOnSet;
	bool m_bGenerateOnStart;
	EForwardRule m_eForwardRule;
	ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull> m_ChangedEvent;
	TArray<ZHM5ValueReceiver_bool*> m_ReceiverList;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5ValueEntity_bool() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	bool GetBoolConditionValue() override;
	ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull>& GetBoolConditionChangedEvent() override;

	ZVariant GetValue() override;

	ZHM5ValueEntity_bool() = default;
	static void RegisterType();
	ZHM5ValueEntity_bool(ZComponentCreateInfo& Info);
	void RegisterReceiver(ZHM5ValueReceiver_bool* pReceiver);
	void UnregisterReceiver(ZHM5ValueReceiver_bool* pReceiver);
	void OnSet(const bool& value);
	void OnSetTrue();
	void OnSetFalse();
	void OnGet();
	void ForwardValue(const bool& bOld);
	void SetValue(const bool& bNewValue);
	void HandleValueForwarding(bool bValueChanged);
	void FirePin();
	void SendValueToReceivers();
};
