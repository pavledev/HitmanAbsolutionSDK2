#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "TResourcePtr.h"
#include "EWeaponUpgradeIcon.h"
#include "EWeaponUpgradeUse.h"
#include "SComponentMapEntry.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZTextListData;
struct STypeID;

class ZHM5WeaponUpgradeEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<ZHM5WeaponUpgradeEntity> m_NextLevel;
	ZString m_TitleLoganID;
	ZString m_DescriptionLoganID;
	TResourcePtr<ZTextListData> m_pTextListResource;
	EWeaponUpgradeIcon m_eMenuIcon;
	int m_iUnlockPrice;
	int m_iPOICost;
	float m_fStatsRangeDelta;
	float m_fStatsDamageDelta;
	float m_fStatsAccuracyDelta;
	float m_fStatsFireRateDelta;
	bool m_bStartsActive;
	EWeaponUpgradeUse m_eWeaponUpgradeUse;
	bool m_bStartsDual;
	float m_fDamageCloseBonus;
	float m_fDamageNearBonus;
	float m_fDamageMediumBonus;
	float m_fDamageFarBonus;
	float m_fDamageMultiplierBonus;
	float m_fRangeCloseBonus;
	float m_fRangeNearBonus;
	float m_fRangeMediumBonus;
	float m_fRangeFarBonus;
	int m_iBulletsPerMagazineBonus;
	float m_fInitialMagazinesBonus;
	float m_fShotsPerMinuteBonus;
	float m_fReloadSpeedFactorBonus;
	float m_fRecoilXPenalty;
	float m_fRecoilZPenalty;
	int m_iPrecisionNumBonus;
	float m_fPrecisionMinDegreePenalty;
	float m_fPrecisionMaxDegreePenalty;
	bool m_bMakeSilenced;
	bool m_bMakeRedDot;
	bool m_bShowBoneA;
	ZString m_BoneNameA;
	bool m_bShowBoneB;
	ZString m_BoneNameB;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5WeaponUpgradeEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHM5WeaponUpgradeEntity() = default;
	static void RegisterType();
	ZHM5WeaponUpgradeEntity(ZComponentCreateInfo& info);
	void GetLocalStrings(ZString& sTitle, ZString& sDesc) const;
	bool GetStartsActive() const;
	void SetStartsActive(bool bActive);
};
