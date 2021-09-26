#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "SComponentMapEntry.h"
#include "ZEntityRef.h"
#include "ZVariantRef.h"

class ZActor;
class ZComponentCreateInfo;
class ZString;
struct STypeID;

class ZActorEventEmitter : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZEntityRef m_pActor;
	TEntityRef<ZActor> m_pActorInternal;
	bool m_bRegistered;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int s_HitmanInSight;
	static unsigned int s_HitmanFullAttention;
	static unsigned int s_ShootingBalletKillTagged;

	~ZActorEventEmitter() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;

	ZActorEventEmitter() = default;
	static void RegisterType();
	ZActorEventEmitter(ZComponentCreateInfo& info);
	TEntityRef<ZActor> GetActor();
	void FireAmbient();
	void FireAlert();
	void FireAlertHigh();
	void FireArrest();
	void FireCombat();
	void FireDead();
	void FireSpeaking(int nSpeaking);
	void FireInSequence(int nInSequence);
	void FireArmed(int nSpeaking);
	void FireHitFirstTime();
	void FireWounded(int nWounded);
	void FireSpottedByHitman();
	void FireOutfitTaken();
	void FireHumanShield();
	void FireHitmanInSight(bool bInSight);
	void FireHitmanFullAttention(bool bFullAttention);
	void FireShootingBalletKillTagged();
};
