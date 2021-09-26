#pragma once

#include "TMaxArray.h"
#include "ZEvent.h"
#include "ZGameTime.h"
#include "EActorType.h"
#include "TEntityRef.h"
#include "TArrayRef.h"

class ZSituationMember;
class ZSituationBase;
class ZActor;
struct float4;
class IHM5Outfit;
class ZEventNull;
template <class T> class TRefCountPtr;

class ZSharedDeadBodySensor
{
public:
	struct SDeadBodyInfo
	{
		TEntityRef<ZActor> m_rActor;
		TMaxArray<TEntityRef<ZActor>, 100> m_knownByActors;
		bool m_bPoolKnownOnly;
		bool m_bPoolInvestigated;
		bool m_bBodyInvestigated;
		bool m_bHidden;
		bool m_bDeadByAccident;
		bool m_bDeadByUnnoticed;
		bool m_bHitmanSuspectedInCurrentOutfit;
		ZGameTime m_tDeadSince;
		ZGameTime m_tKnownSince;
		ZGameTime m_tInvestigatedSince;

		SDeadBodyInfo(const SDeadBodyInfo& __that);
		SDeadBodyInfo() = default;
		~SDeadBodyInfo() = default;
		SDeadBodyInfo& operator=(const SDeadBodyInfo& __that);
	};

	TMaxArray<SDeadBodyInfo, 100> m_bodies;
	int m_nBodyIndex;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_LastWitnessKilledEvent;

	ZSharedDeadBodySensor() = default;
	~ZSharedDeadBodySensor() = default;
	const TMaxArray<SDeadBodyInfo, 100>& KnownDeadBodies() const;
	void RegisterSuspiciousBody(const TEntityRef<ZActor>& rActor);
	bool AreAnyMembersAwareOfBody(const TEntityRef<ZActor>& rActor, const TMaxArray<TRefCountPtr<ZSituationMember>, 64>& aMembers, EActorType eActorType);
	bool IsActorAwareOfBody(const TEntityRef<ZActor>& rActor, const TEntityRef<ZActor>& rDeadBody);
	bool IsAnyoneAwareOfBody(const TEntityRef<ZActor>& rDeadBody);
	TEntityRef<ZActor> GetClosestFreshBody(const float4& vPosition, float fMaxDistance, float& fDistance);
	void MarkHitmanAsSuspectToBody(const TEntityRef<ZActor>& rActor);
	void MarkBodyAsHidden(const TEntityRef<ZActor>& rActor);
	void MarkBodiesAsInvestigated(const float4& vPosition, float fRadius);
	void MarkBloodpoolAsInvestigated(const TEntityRef<ZActor>& rActor);
	bool HasBloodpoolBeenInvestigated(const TEntityRef<ZActor>& rActor);
	void ClearActorBodyKnowledge(const TEntityRef<ZActor>& rActor);
	int GetNumBodiesKnown(const TEntityRef<ZActor>& rActor);
	int CountBodiesSeenInArea(TEntityRef<ZActor> pActor, const float4& vPosition, float fRadius, bool bFreshBodiesOnly);
	void Reset();
	void Update(const TArrayRef<TEntityRef<ZActor>>& actors);
	void OutfitChangedEventHandler(TEntityRef<IHM5Outfit> pOldOutfit, TEntityRef<IHM5Outfit> pNewOutfit);
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetLastWitnessKilledEvent();
	TArrayRef<SDeadBodyInfo> GetDeadBodyArray();
	void PropagateKnowledgeWithinSituation(const TEntityRef<ZSituationBase>& pSituation, SDeadBodyInfo& body);
};
