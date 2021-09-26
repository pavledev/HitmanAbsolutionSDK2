#pragma once

#include "ZStreamingRootEntityBase.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZStreamingRootEntity : public ZStreamingRootEntityBase
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	static SComponentMapEntry s_componentMap[0];

	~ZStreamingRootEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZStreamingRootEntity() = default;
	static void RegisterType();
	ZStreamingRootEntity(ZComponentCreateInfo& Info);
};
