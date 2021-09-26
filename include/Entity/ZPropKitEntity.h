#pragma once

#include "ZContentKitEntity.h"
#include "SComponentMapEntry.h"
#include "ZRuntimeResourceID.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZPropKitEntity : public ZContentKitEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZRuntimeResourceID m_sHiResNotebookImage;
	bool m_bIsNewPickup;

	static SComponentMapEntry s_componentMap[0];

	~ZPropKitEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	bool PickedUp(int lvl, int cp) override;
	bool WasPickedUp(int lvl, int cp) override;
	bool IsNewPickUp(int lvl, int cp) override;

	ZPropKitEntity() = default;
	static void RegisterType();
	ZPropKitEntity(ZComponentCreateInfo& Info);
	ZRuntimeResourceID GetLargeIconRID() const;
};
