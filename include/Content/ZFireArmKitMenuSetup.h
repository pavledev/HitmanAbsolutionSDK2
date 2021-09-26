#pragma once

#include "ZContentKitMenuSetup.h"
#include "ZHM5WeaponConfigurator.h"
#include "MenuWeaponUpgradeData.h"
#include "SComponentMapEntry.h"
#include "ZRuntimeResourceID.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZFireArmKitMenuSetup : public ZContentKitMenuSetup
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZRuntimeResourceID m_WeaponResource;
	ZHM5WeaponConfigurator m_Configurator;

	static SComponentMapEntry s_componentMap[0];

	~ZFireArmKitMenuSetup() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void OnSavegameLoadDone() override;
	void BeforeUnregisterKit() override;
	void AfterRegisterKit() override;

	ZFireArmKitMenuSetup() = default;
	static void RegisterType();
	ZFireArmKitMenuSetup(ZComponentCreateInfo& Info);
	bool UpgradeMenuAction(int nUpgradeIndex, MenuWeaponUpgradeData::EUpgradeAction eAction, int nSlot);
	bool QueryUpgradePrice(int nUpgradeIndex, int& iPrice, int& iNewLevel);
	bool QuerySlotPrice(int& iPrice, int& iNewLevel);
	void UnlockAllUpgrades();
	ZHM5WeaponConfigurator& GetConfigurator();
	void RefreshUpgradeInfo();
};
