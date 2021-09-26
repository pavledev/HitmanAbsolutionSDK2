#pragma once

#include "SContentKitBaseState.h"
#include "TFixedArray.h"
#include "TArray.h"
#include "MenuWeaponUpgradeData.h"

struct SFireArmKitState : SContentKitBaseState
{
	enum
	{
		eSAVEGAME_NOT_VALID = 255
	};

	unsigned int m_iUpgUnLocked;
	TFixedArray<signed char, 4> m_iUpgInstalled;
	unsigned char m_iUpgUnlockedSlots;
	unsigned char m_iUpgradesNum;
	TArray<unsigned char> m_PickupState;

	SFireArmKitState(const SFireArmKitState& __that);
	SFireArmKitState() = default;
	MenuWeaponUpgradeData::EWUpgradeLevel GetUnlockedLevel(int iIndex) const;
	void SetUnLockedLevel(int iIndex, MenuWeaponUpgradeData::EWUpgradeLevel eVal);
	MenuWeaponUpgradeData::EWUpgradeLevel GetInstalledLevel(int iIndex) const;
	void SetInstalled(char iIndex, bool bInstalled);
	void SetInstalledInSlot(char iIndex, int iSlot);
	bool SetPickedUp(int lvl, int cp);
	bool WasPickedUp(int lvl, int cp);
	MenuWeaponUpgradeData::EWUpgradeLevel ReadValueForIndex(unsigned int iMember, int iIndex) const;
	void SetValueForIndex(unsigned int& iMember, int iIndex, MenuWeaponUpgradeData::EWUpgradeLevel eVal);
	~SFireArmKitState() = default;
	SFireArmKitState& operator=(const SFireArmKitState& __that);
};
