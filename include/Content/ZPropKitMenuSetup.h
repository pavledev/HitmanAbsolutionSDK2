#pragma once

#include "ZContentKitMenuSetup.h"
#include "SComponentMapEntry.h"
#include "ZRuntimeResourceID.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZPropKitMenuSetup : public ZContentKitMenuSetup
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZRuntimeResourceID m_WeaponResource;

	static SComponentMapEntry s_componentMap[0];

	~ZPropKitMenuSetup() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZPropKitMenuSetup() = default;
	static void RegisterType();
	ZPropKitMenuSetup(ZComponentCreateInfo& Info);
};
