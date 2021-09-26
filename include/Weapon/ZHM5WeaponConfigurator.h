#pragma once

#include "SHM5WeaponConfig.h"
#include "TSet.h"
#include "ZString.h"
#include "TEntityRef.h"
#include "ZHM5WeaponBasicConfigEntity.h"
#include "ZFireArmKitEntity.h"
#include "MenuWeaponUpgradeData.h"
#include "TMap.h"

class ZHM5ItemWeapon;

class ZHM5WeaponConfigurator
{
public:
	enum EWeaponUpgConfig
	{
		eWUC_ConfigPrimary = 0,
		eWUC_ConfigSecondary = 1,
		eWUC_ConfigNPC = 2,
		eWUC_NUM = 3
	};

	SHM5WeaponConfig m_Configs[3];
	TSet<ZString> m_VisibleBones[3];
	TEntityRef<ZHM5WeaponBasicConfigEntity> m_rBasicConfig;
	TEntityRef<ZFireArmKitEntity> m_rFireArmKit;
	EWeaponUpgConfig m_eCurrentConfig;
	unsigned char m_iPossibleUpgrades;
	bool m_bInitialized;
	bool m_bSavegameAuthority;
	bool m_bDirty;

	ZHM5WeaponConfigurator() = default;
	~ZHM5WeaponConfigurator() = default;
	void MarkUnInitialized();
	bool IsInitializedFromKit() const;
	void SetBasicConfigEntity(const TEntityRef<ZHM5WeaponBasicConfigEntity>& rBasicConfig);
	void SetFireArmKitEntity(const TEntityRef<ZFireArmKitEntity>& rFireArmKit);
	void SetupConfigurations(const TEntityRef<ZHM5ItemWeapon>& rWeapon, bool bInfoFromKit, bool bAllowSaveGameUpgrades);
	const SHM5WeaponConfig& GetCurrentConfig() const;
	void ChangeOperMode(EWeaponUpgConfig newConfig);
	void GetBoneStates(TMap<ZString, bool>& map) const;
	void PrepMenuData(const TEntityRef<ZFireArmKitEntity>& rFireArm);
	bool MenuAction_Install(int nUpgradeIndex, int nSlot);
	bool MenuAction_InstallPOI(int nUpgradeIndex);
	bool MenuAction_Remove(int nUpgradeIndex);
	bool MenuAction_BuyNextLevel(int nUpgradeIndex, bool bQueryPrice, int& iPrice, int& iNewLevel);
	bool MenuAction_UnlockSlot(bool bQueryPrice, int& iPrice, int& iNewLevel);
	bool MenuAction_UnlockSlotPOI();
	bool MenuAction_ClearLevels(int nUpgradeIndex);
	bool MenuAction_UnlockNextLevel(int nUpgradeIndex);
	void GetMenuData(MenuWeaponUpgradeData::SHM5WeaponUpgrades& menuData) const;
	void AllowSavegameModifications();
	void CheatUnlockAllSlots() const;
	MenuWeaponUpgradeData::EWUpgradeLevel GetMaxPossibleUpgradeLevel(unsigned int iUpgrade) const;
	void FillUpgradesResponseData(MenuWeaponUpgradeData::SHM5WeaponUpgradesResponse& upgradeResponse, MenuWeaponUpgradeData::EUpgradeAction eAction) const;
	void UnlockAllUpgrades();
	void SetupConfigurations_FromWeapon(const TEntityRef<ZHM5ItemWeapon>& rWeapon);
	void ApplyUpgradeOnConfig(EWeaponUpgConfig eConfig, const ZHM5WeaponUpgradeEntity* pUpgrade, int iLevel);
};
