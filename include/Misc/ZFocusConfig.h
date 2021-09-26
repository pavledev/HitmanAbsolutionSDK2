#pragma once

#include "ZEntityImpl.h"
#include "ZResourcePtr.h"
#include "SVector2.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

struct float4;
class ZComponentCreateInfo;
struct STypeID;

class ZFocusConfig : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fMax;
	float m_fInitial;
	float m_fGainFromHealthStation;
	float m_fGainNoKillsOnCP;
	float m_fGainHeadShot;
	float m_fGainFiberwireKill;
	float m_fGainEnvironmentKill;
	float m_fGainAccidentKill;
	float m_fGainHideBody;
	float m_fGainFromDisguiseUnlock;
	float m_fGainUnspottedOnCP;
	float m_fGainChokeOut;
	float m_fGainKnockOut;
	float m_fGainSnapNeck;
	float m_fGainItemKillFront;
	float m_fGainItemKillBack;
	float m_fGainItemThrowKill;
	float m_fGainPistolExecute;
	float m_fGainObjectiveComplete;
	float m_fGainObjectiveCompleteInStealth;
	float m_fBlendInMin;
	float m_fSBMinimumFocus;
	float m_fSBFocusToDamageRatio;
	float m_fSBPropDamageCost;
	float m_fKillCivilanDrain;
	float m_fSniperSlowDownUseRate;
	float m_fFocusShotUseRate;
	float m_fPreciseShotUseRate;
	float m_fDamageThreshold;
	float m_fFocusCostOnDamage;
	float m_fFocusMinUseRate;
	float m_fFocusMaxUseRate;
	float m_fInstinctMinFocus;
	bool m_bSniperSlowDownCostEnable;
	bool m_bFocusShotCostEnable;
	float m_fHideInPlainSight_GainCap;
	ZResourcePtr m_mHighlightMaterialHigh;
	ZResourcePtr m_mHighlightMaterialLow;
	ZResourcePtr m_mHighlightMaterialCounter;
	SVector2 m_vHighlightSize;
	bool m_bIsForDifficulty;

	static SComponentMapEntry s_componentMap[0];

	~ZFocusConfig() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZFocusConfig() = default;
	static void RegisterType();
	ZFocusConfig(ZComponentCreateInfo& info);
	float GetMax() const;
	float GetInitial() const;
	float GetGainNoKillsOnCP() const;
	float GetGainHeadShot() const;
	float GetGainFiberwireKill() const;
	float GetGainHideBody() const;
	float GetGainUnspottedOnCP() const;
	float GetGainChokeOut() const;
	float GetGainKnockOut() const;
	float GetGainAccident() const;
	float GetGainSnapNeck() const;
	float GetEnvironmentKill() const;
	float GetItemKillFront() const;
	float GetItemKillBack() const;
	float GetItemThrowKill() const;
	float GetGainPistolExecute() const;
	float GetObjectiveCompleteGain() const;
	float GetObjectiveCompleteInStealthGain() const;
	float GetBlendInMin() const;
	float GetSBMinimumFocus() const;
	float GetSBFocusToDamageRatio() const;
	float GetSBPropDamageCost() const;
	float GetKillCivilianDrain() const;
	float GetSniperSlowDownUseRate() const;
	float GetFocusShotUseRate() const;
	float GetPreciseShotUseRate() const;
	float GetFocusMinUseRate() const;
	float GetFocusMaxUseRate() const;
	float GetInstinctMinFocus() const;
	bool SniperSlowDownCostEnable() const;
	bool FocusShotCostEnable() const;
	const ZResourcePtr& GetHighlightMaterialHigh() const;
	const ZResourcePtr& GetHighlightMaterialLow() const;
	const ZResourcePtr& GetHighlightMaterialCounter() const;
	float4 GetHighlightSize() const;
	float GetGainFromDisguiseUnlock() const;
	float GetHideInPlainSight_GainCap() const;
};
