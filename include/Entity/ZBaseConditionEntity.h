#pragma once

#include "ZEntityImpl.h"
#include "IBoolCondition.h"
#include "SComponentMapEntry.h"
#include "ZEvent.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZEventNull;
struct STypeID;
template <class T> class TEntityRef;

class ZBaseConditionEntity : public ZEntityImpl, public IBoolCondition
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull> m_ChangedEvent;
	bool m_bConditionValue;
	bool m_bIsActive;

	static SComponentMapEntry s_componentMap[0];

	~ZBaseConditionEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	bool GetBoolConditionValue() override;
	ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull>& GetBoolConditionChangedEvent() override;

	ZBaseConditionEntity() = default;
	static void RegisterType();
	ZBaseConditionEntity(ZComponentCreateInfo& info);
	void SetConditionValue(bool bNewValue);
	void OnActivate();
	void OnDeactivate();
};
