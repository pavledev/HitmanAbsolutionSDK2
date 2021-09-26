#pragma once

#include "ZEntityImpl.h"
#include "IValueEntity.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZString;
struct STypeID;

class __declspec(novtable) ZHM5ValueEntity_Base : public ZEntityImpl, public IValueEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bForwardOnSet;
	bool m_bGenerateOnStart;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5ValueEntity_Base() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	virtual void FirePin() = 0;
	virtual void SendValueToReceivers() = 0;

	ZHM5ValueEntity_Base() = default;
	static void RegisterType();
	ZHM5ValueEntity_Base(ZComponentCreateInfo& Info);
	void OnValueChanged();
};
