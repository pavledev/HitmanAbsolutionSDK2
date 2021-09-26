#pragma once

#include "TArray.h"
#include "TFixedArray.h"
#include "EWeaponUpgradeIcon.h"
#include "ZString.h"

namespace MenuWeaponUpgradeData
{
	enum
	{
		MAX_UPGRADE_INSTALL = 3
	};

	enum EUpgradeAction
	{
		EUPGRADE_ACTION_NONE = 0,
		EUPGRADE_ACTION_INSTALL = 1,
		EUPGRADE_ACTION_REMOVE = 2,
		EUPGRADE_ACTION_UNLOCK_SLOT = 3,
		EUPGRADE_ACTION_BUY_NEXT_LEVEL = 4,
		EUPGRADE_ACTION_EQUIP_WEAPON = 5,
		EUPGRADE_ACTION_UNEQUIP_WEAPON = 6,
		EUPGRADE_ACTION_CLEAR_LEVELS = 7
	};

	enum EWUpgradeLevel
	{
		UPGRADE_LEVELS = 3,
		eUPL_NoLevel = 0,
		eUPL_Level1 = 1,
		eUPL_Level2 = 2,
		eUPL_Level3 = 3
	};

	enum EMenuUpgAttribute
	{
		eMUA_Range = 0,
		eMUA_Damage = 1,
		eMUA_Accuracy = 2,
		eMUA_FireRate = 3,
		eMUA_NUM = 4
	};

	struct SHM5WeaponUpgradesResponse
	{
		TArray<EWUpgradeLevel> m_UpgradeUnlockedLevel;
		TFixedArray<int, 3> m_InstalledUpgradeIndexes;
		EUpgradeAction m_eActionType;
		int m_iAvailableSlots;
		int m_iIndexUsed;
		bool m_bUnlockSuccess;

		SHM5WeaponUpgradesResponse() = default;
		void Reset();
		~SHM5WeaponUpgradesResponse() = default;
	};

	struct SHM5UpgradeLevel
	{
		TFixedArray<float, 4> m_UpgDeltas;
		ZString m_sTitle;
		ZString m_sDescription;
		int m_iUnlockPrice;
		int m_iPOIUnlockPrice;

		SHM5UpgradeLevel(const SHM5UpgradeLevel& __that);
		SHM5UpgradeLevel() = default;
		~SHM5UpgradeLevel() = default;
	};

	struct SHM5Upgrade
	{
		TFixedArray<SHM5UpgradeLevel, 3> m_UpgLevels;
		EWUpgradeLevel m_ePresentLevels;
		EWUpgradeLevel m_eUnlockedLevel;
		EWeaponUpgradeIcon m_eMenuIcon;
		bool m_bInstalled;

		SHM5Upgrade(const SHM5Upgrade& __that);
		SHM5Upgrade() = default;
		~SHM5Upgrade() = default;
	};

	struct SHM5WeaponUpgrades
	{
		TFixedArray<float, 4> m_WeaponStatsCurrent;
		TArray<SHM5Upgrade> m_AllUpgrades;
		TFixedArray<int, 3> m_SlotsUnlockPrice;
		TFixedArray<int, 3> m_InstalledUpgradeIndexes;
		int m_iAvailableSlots;
		bool m_bUpgradesVisible;
		bool m_bInitialized;

		SHM5WeaponUpgrades() = default;
		void Reset();
		~SHM5WeaponUpgrades() = default;
	};
};