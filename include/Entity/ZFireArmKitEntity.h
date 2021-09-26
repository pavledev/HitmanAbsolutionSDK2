#pragma once

#include "ZContentKitEntity.h"
#include "SComponentMapEntry.h"
#include "TEntityRef.h"
#include "ZRuntimeResourceID.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZHM5WeaponBasicConfigEntity;
struct STypeID;

class ZFireArmKitEntity : public ZContentKitEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<ZHM5WeaponBasicConfigEntity> m_BasicConfig;
	ZRuntimeResourceID m_sHiResNotebookImage;
	bool m_bIsNewPickup;

	static SComponentMapEntry s_componentMap[0];

	~ZFireArmKitEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	bool PickedUp(int lvl, int cp) override;
	bool WasPickedUp(int lvl, int cp) override;
	bool IsNewPickUp(int lvl, int cp) override;

	ZFireArmKitEntity() = default;
	static void RegisterType();
	ZFireArmKitEntity(ZComponentCreateInfo& Info);
	const TEntityRef<ZHM5WeaponBasicConfigEntity>& GetBasicConfigEntity() const;
	ZRuntimeResourceID GetLargeIconRID() const;
};
