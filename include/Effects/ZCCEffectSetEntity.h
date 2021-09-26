#pragma once

#include "ZEntityImpl.h"
#include "ECCDecalEffect.h"
#include "ECCEmitterEffect.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZCCEffectSetEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ECCDecalEffect m_eDecalEffect;
	ECCEmitterEffect m_eEmitterEffect;
	unsigned int m_nEvent;

	static SComponentMapEntry s_componentMap[0];

	~ZCCEffectSetEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZCCEffectSetEntity() = default;
	static void RegisterType();
	ZCCEffectSetEntity(ZComponentCreateInfo& pInfo);
};
