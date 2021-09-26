#pragma once

#include "ZEntityImpl.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZHM5WeaponUpgradeEntity;
struct STypeID;
template <class T> class TEntityRef;

class ZHM5WeaponBasicConfigEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TArray<TEntityRef<ZHM5WeaponUpgradeEntity>> m_Upgrades;
	bool m_bUpgradesVisibleInMenu;
	int m_iUnlockPriceSlot1;
	int m_iUnlockPriceSlot2;
	int m_iUnlockPriceSlot3;
	float m_fStatsRange;
	float m_fStatsDamage;
	float m_fStatsAccuracy;
	float m_fStatsFireRate;
	float m_fDamageClose;
	float m_fDamageNear;
	float m_fDamageMedium;
	float m_fDamageFar;
	float m_fDamageMultiplier;
	float m_fRangeClose;
	float m_fRangeNear;
	float m_fRangeMedium;
	float m_fRangeFar;
	int m_iBulletsPerMagazine;
	float m_fInitialMagazines;
	int m_iShotsPerMinute;
	float m_fReloadFactor;
	int m_iPrecisionNumBullets;
	float m_fPrecisionMinDegree;
	float m_fPrecisionMaxDegree;
	float m_fRecoilX;
	float m_fRecoilZ;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5WeaponBasicConfigEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHM5WeaponBasicConfigEntity() = default;
	static void RegisterType();
	ZHM5WeaponBasicConfigEntity(ZComponentCreateInfo& info);
	unsigned int GetUpgradesSize() const;
	const ZHM5WeaponUpgradeEntity* const GetUpgrade(unsigned int index) const;
	TArrayRef<TEntityRef<ZHM5WeaponUpgradeEntity>> GetUpgrades();
	const ZHM5WeaponBasicConfigEntity& GetBasicConfigEntity() const;
};
