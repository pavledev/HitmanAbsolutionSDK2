#pragma once

#include "TMaxArray.h"
#include "SCombatTimer.h"
#include "TEntityRef.h"
#include "ZGameTime.h"
#include "TArrayRef.h"

class ZSocialActor;
class ZActor;
class ZHM5BaseCharacter;
class ZHitman5;
class ZSharedKnowledgeRef;
class ZSocialSensorDef;

class ZSocialSensor
{
public:
	enum ESocialInteractionType
	{
		SIT_None = 0,
		SIT_HitmanMonitor = 1,
		SIT_LookAt = 2,
		SIT_Greeting = 3,
		SIT_DisguiseGreeting = 4,
		SIT_HIPSGreeting = 5
	};

	enum ESocialActorState
	{
		SAS_Candidate = 0,
		SAS_InteractHitman = 1,
		SAS_ConsiderActor = 2,
		SAS_InteractActor = 3,
		SAS_Cooldown = 4,
		SAS_Purge = 5
	};

	struct SSocialActorData
	{
		TEntityRef<ZActor> m_pActor;
		TEntityRef<ZSocialActor> m_pSocialActorEntity;
		TEntityRef<ZActor> m_pInteractActor;
		TEntityRef<ZHM5BaseCharacter> m_pLastLookAt;
		ESocialActorState m_eState;
		ESocialInteractionType m_eInteractionType;
		int m_iNextActorIndex;
		float m_tHitmanStandingTime;
		ZGameTime m_tHitmanRunningTime;
		float m_tHitmanSillyTime;
		SCombatTimer m_tCooldown;
		SCombatTimer m_tBored;
		bool m_bAmbientLookAt;
		bool m_bGreeting;
		bool m_bCanGreet;
		bool m_bNewCandidate;

		void Init();
		SSocialActorData(const SSocialActorData& __that);
		SSocialActorData() = default;
		~SSocialActorData() = default;
		SSocialActorData& operator=(const SSocialActorData& __that);
	};

	TMaxArray<SSocialActorData, 16> m_aSocialActors;
	TEntityRef<ZHitman5> m_pHitman;
	TEntityRef<ZSocialSensorDef> m_pSensorDef;
	TArrayRef<TEntityRef<ZActor>> m_aActors;
	SCombatTimer m_tCooldownRunning;
	SCombatTimer m_tCooldownStanding;
	SCombatTimer m_tCooldownGreeting;
	SCombatTimer m_tCooldownSilly;
	int m_nActorCandidate;

	ZSocialSensor() = default;
	~ZSocialSensor() = default;
	void GameStarted();
	void GameStopped();
	void Reset();
	void Update(const TArrayRef<TEntityRef<ZActor>>& actors);
	void ApplyHitmanGreetingCooldown();
	void SelectCandidate();
	void UpdateSocialActors();
	void Candidate(SSocialActorData* pSocialActor);
	void InteractHitman(SSocialActorData* pSocialActor);
	void ConsiderActors(SSocialActorData* pSocialActor);
	void InteractActor(SSocialActorData* pSocialActor);
	void Cooldown(SSocialActorData* pSocialActor);
	bool CanInteractHitman(SSocialActorData* pSocialActor);
	bool TestHitmanGridProximity(SSocialActorData* pSocialActor);
	bool TestActorGridProximity(SSocialActorData* pSocialActor, TEntityRef<ZActor> pOtherActor);
	bool TestHitmanLookat(SSocialActorData* pSocialActor);
	bool TestActorLookat(SSocialActorData* pSocialActor, TEntityRef<ZActor> pOtherActor);
	void UpdateHitmanLookat(SSocialActorData* pSocialActor);
	void UpdateActorLookat(SSocialActorData* pSocialActor);
	bool IsAlreadySocial(TEntityRef<ZActor> pActor);
	bool IsHitmanSilly(SSocialActorData* pSocialActor);
	bool IgnoreHitmanSilly(SSocialActorData* pSocialActor);
	bool TestHitmanSillyEvents(const ZSharedKnowledgeRef& rHitman);
	void StopSocialising(SSocialActorData* pSocialActor);
};
