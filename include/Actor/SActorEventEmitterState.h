#pragma once

#include "TEntityRef.h"
#include "EGameTension.h"
#include "TMaxArray.h"

class IAsyncRayHandle;
class ZActor;
class ZActorEventEmitter;

struct SActorEventEmitterState
{
	class ZActorCompare
	{
	public:
		TEntityRef<ZActor> m_rActor;

		ZActorCompare(const TEntityRef<ZActor>& rActor);
		bool operator()(const SActorEventEmitterState& rsh);
		~ZActorCompare() = default;
	};

	TEntityRef<ZActor> m_rActor;
	TMaxArray<ZActorEventEmitter*, 6> m_emitters;
	EGameTension m_eTension;
	bool m_bDead : 1;
	bool m_bArmed : 1;
	bool m_bWounded : 1;
	bool m_bSpeaking : 1;
	bool m_bInSequence : 1;
	bool m_bFirstHit : 1;
	bool m_bOnScreen : 1;
	bool m_bOutfitTaken : 1;
	bool m_bFirstOnScreen : 1;
	bool m_bFirstOnScreenSound : 1;
	bool m_bSBTimeAdded : 1;
	bool m_bSBTimeSubtracted : 1;
	bool m_bHumanShield : 1;
	bool m_bHitmanInSight : 1;
	bool m_bHitmanFullAttention : 1;
	bool m_bSBKillTagAdded : 1;
	float m_fSBActorSubtractReactTime;
	unsigned int m_nRayIndex;
	unsigned int m_nMissedRayTests;
	IAsyncRayHandle* m_pCollisionHandle;

	static const unsigned int NUM_RAY_TEST;
	static const int MAX_ACTOR_EMITTERS;

	SActorEventEmitterState(const SActorEventEmitterState& __that);
	SActorEventEmitterState() = default;
	~SActorEventEmitterState() = default;
	SActorEventEmitterState& operator=(const SActorEventEmitterState& __that);
};
