#pragma once

#include "ZSpatialEntity.h"
#include "EGameTension.h"
#include "ZHM5Outfit.h"
#include "ZActor.h"
#include "ZGameTime.h"

class ZSocialActor : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bEnabled;
	bool m_bDisguiseGreetingsEnabled;
	EGameTension m_eRequiredActorTension;
	float m_fCooldown;
	float m_fGreetingChance;
	float m_fResponseChance;
	float m_fHitmanGreetingChance;
	float m_fRadius;
	float m_fMinInSightTime;
	bool m_bTestActors;
	bool m_bTestHitman;
	TArray<TEntityRef<ZHM5Outfit>> m_aOutfits;
	TEntityRef<ZActor> m_pActorToControl;
	ZGameTime m_fCooldownTimer;
	bool m_bActivated;
	bool m_bRegistered;

	static SComponentMapEntry s_componentMap[0];

	~ZSocialActor() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	ZSocialActor() = default;
	static void RegisterType();
	ZSocialActor(ZComponentCreateInfo& info);
	bool TriggerGreeting(bool bHitman, TEntityRef<ZSocialActor> pResponder);
	void TriggerResponse();
	int TriggerDisguiseGreetingPin(const SOutfitData& data);
	const TEntityRef<ZActor>& GetControlledActor() const;
	bool CanGreetHitman() const;
	bool CanGreetActors() const;
	bool IsDisguiseRecognized(const SOutfitData& data) const;
	void SignalOnStopSocialising();
	bool IsDisguiseGreetingsEnabled() const;
	float GetGreetingRadius();
	float GetMinInSightTime();
	void OnEnable();
	void OnDisable();
	void OnEnableDisguiseGreetings();
	void OnDisableDisguiseGreetings();
	void OnEnabledChanged();
	void OnDisguiseGreetingsEnabledChanged();
	void Register();
	void Unregister();
};
