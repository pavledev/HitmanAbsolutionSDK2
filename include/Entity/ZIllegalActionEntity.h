#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class IBoolCondition;
class ZComponentCreateInfo;
class ZString;
struct STypeID;

class ZIllegalActionEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bIsIllegal;
	float m_fDuration;
	TEntityRef<IBoolCondition> m_pEnabledCondition;
	TEntityRef<IBoolCondition> m_pOutfitCondition;

	static SComponentMapEntry s_componentMap[0];

	~ZIllegalActionEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	ZIllegalActionEntity() = default;
	static void RegisterType();
	ZIllegalActionEntity(ZComponentCreateInfo& Info);
	bool IsCurrentlyIllegal() const;
	void OnTrigger();
	void OnAbort();
};
