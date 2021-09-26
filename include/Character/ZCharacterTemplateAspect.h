#pragma once

#include "ZEntityImpl.h"
#include "ZResourcePtr.h"
#include "ZRuntimeResourceID.h"
#include "EActorCCPreset.h"
#include "TEntityRef.h"
#include "SBodyPartDamageMultipliers.h"
#include "ESettingsParam.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "TResourcePtr.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZEntityRef;
class ZLinkedProxyEntity;
class ZString;
struct SSettingsParamMultiplier;
struct STypeID;
template <class A, class B> class THashSet;
template <class T> class TDefaultHashSetPolicy;

class ZCharacterTemplateAspect : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZResourcePtr m_NudeResource;
	ZRuntimeResourceID m_HMAsResID;
	TArray<ZString> m_CharacterStatLabelList;
	EActorCCPreset m_eActorCCClass;
	bool m_bIsFemale;
	TEntityRef<ZLinkedProxyEntity> m_NudeEntity;
	TResourcePtr<ZEntityRef> m_sHUDPortraitShared;
	float m_fHitPoints;
	SBodyPartDamageMultipliers m_DamageMultipliers;
	bool m_bAllowRadioAct;
	bool m_bDisableRating;
	TArray<SSettingsParamMultiplier> m_SettingsParamMultipliers;
	bool m_bStreamedIn : 1;
	bool m_bIsNude : 1;

	static SComponentMapEntry s_componentMap[0];

	~ZCharacterTemplateAspect() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	void GetStreamableIncludes(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef>>& streamableIncludes) const override;
	void Init() override;

	ZCharacterTemplateAspect() = default;
	static void RegisterType();
	ZCharacterTemplateAspect(ZComponentCreateInfo& info);
	ZRuntimeResourceID GetHMAsResourceID() const;
	void SetHitmanAsResourceId(ZRuntimeResourceID HitmanAsResourceID);
	bool IsNude() const;
	void ChangeToNude();
	bool IsFemale() const;
	TArray<ZString>& GetCharacterStatLabels();
	TResourcePtr<ZEntityRef> GetHUDPortrait() const;
	float GetInitHitPoints() const;
	const SBodyPartDamageMultipliers& GetDamageMultipliers();
	EActorCCPreset GetCCPreset() const;
	bool IsRadioActAllowed() const;
	bool IsRatingDisabled() const;
	float GetSettingsParamMultiplier(ESettingsParam eSettingsParam) const;
	void ChangeToNudeInternal();
	void ReleaseNude();
};
