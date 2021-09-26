#pragma once

#include "ZSpatialEntity.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZAISoundConnectorTarget : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	static SComponentMapEntry s_componentMap[0];

	~ZAISoundConnectorTarget() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZAISoundConnectorTarget() = default;
	static void RegisterType();
	ZAISoundConnectorTarget(ZComponentCreateInfo& info);
};
