#pragma once

#include "SSituationInstance.h"
#include "ZSituationBase.h"
#include "ZEvent.h"
#include "TArrayFixedHeap.h"

class ZActorManager;
class ZEventNull;

class ZSituationManager
{
public:
	ZActorManager& m_actorManager;
	TArrayFixedHeap<SSituationInstance, 64> m_situationStorage;
	TMaxArray<SSituationInstance*, 64> m_situations;
	ZEvent<TEntityRef<ZSituationBase> const&, TEntityRef<ZActor> const&, ZEventNull, ZEventNull, ZEventNull> m_actorJoinEvent;
	ZEvent<TEntityRef<ZSituationBase> const&, TEntityRef<ZActor> const&, ZEventNull, ZEventNull, ZEventNull> m_actorLeaveEvent;

	ZSituationManager() = default;
	ZSituationManager(ZActorManager& actorManager);
	~ZSituationManager() = default;
	void Reset(bool bForced);
	ZEvent<TEntityRef<ZSituationBase> const&, TEntityRef<ZActor> const&, ZEventNull, ZEventNull, ZEventNull>& GetActorJoinEvent();
	ZEvent<TEntityRef<ZSituationBase> const&, TEntityRef<ZActor> const&, ZEventNull, ZEventNull, ZEventNull>& GetActorLeaveEvent();
	void OnActorEnabled(const TEntityRef<ZActor>& pActor);
	bool LeaveAllSituations(const TEntityRef<ZActor>& pActor);
	bool LeaveAllOtherSituations(const TEntityRef<ZActor>& pActor, TEntityRef<ZSituationBase> pSituation);
	TEntityRef<ZSituationBase> CreateSituation(ESituationType type, const ZSharedKnowledgeRef& pTargetShared);
	TEntityRef<ZSituationBase> GetSituationForActor(ESituationType type, const TEntityRef<ZActor>& pActor);
	ESituationType GetMaxPrioritySituationForActor(const TEntityRef<ZActor>& pActor);
	void GetSituations(TMaxArray<TEntityRef<ZSituationBase>, 64>& result, ESituationType type);
	void GetSituationsForTarget(ESituationType type, const ZEntityRef& pTarget, TMaxArray<TEntityRef<ZSituationBase>, 64>& result);
	TEntityRef<ZSituationBase> GetFirstSituationsOfType(ESituationType type);
	void GetSituationsForTargetShared(ESituationType type, const ZSharedKnowledgeRef& pTargetShared, TMaxArray<TEntityRef<ZSituationBase>, 64>& result);
	bool HasHostileSituations();
	void Update(const SGameUpdateEvent& updateEvent);
	TArrayIterator<SSituationInstance*> FindSituation(const TEntityRef<ZSituationBase>& pSituation);
	TArrayIterator<SSituationInstance*> TryDeleteSituation(TArrayIterator<SSituationInstance*> situation, bool bForce);
};
