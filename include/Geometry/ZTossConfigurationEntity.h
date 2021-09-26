#pragma once

#include "ZEntityImpl.h"
#include "ZResourcePtr.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZTossConfigurationEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZResourcePtr m_materialArch;
	ZResourcePtr m_materialDisc;

	static SComponentMapEntry s_componentMap[0];

	~ZTossConfigurationEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZTossConfigurationEntity() = default;
	static void RegisterType();
	ZTossConfigurationEntity(ZComponentCreateInfo& info);
	const ZResourcePtr& GetArchMaterial() const;
	const ZResourcePtr& GetDiscMaterial() const;
};
