#pragma once

#include "ZEntityImpl.h"
#include "ZRuntimeResourceID.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZRuntimeResourceIDEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZRuntimeResourceID m_ResourceID;

	static SComponentMapEntry s_componentMap[0];

	~ZRuntimeResourceIDEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZRuntimeResourceIDEntity() = default;
	static void RegisterType();
	ZRuntimeResourceIDEntity(ZComponentCreateInfo& InfO);
	ZRuntimeResourceID GetRID() const;
};
