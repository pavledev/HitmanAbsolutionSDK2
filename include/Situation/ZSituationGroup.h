#pragma once

#include "TEntityRef.h"
#include "TMaxArray.h"
#include "ZActorDialog.h"
#include "ZSituationOrder.h"
#include "TRefCountPtr.h"
#include "TRefCountPtrArg.h"

class ZSituationBase;
class ZSituationMember;

class ZSituationGroup
{
public:
	int m_nRefCount;
	TEntityRef<ZSituationBase> m_rSituation;
	TMaxArray<TRefCountPtr<ZSituationMember>, 8> m_activeMembers;
	STypeID* m_classType;
	int m_nGroupID;

	virtual ~ZSituationGroup() = default;
	virtual void OnMemberActivated(TRefCountPtrArg<ZSituationMember> rMember);
	virtual void OnMemberDeactivated(TRefCountPtrArg<ZSituationMember> rMember);
	virtual void OnOrderClear(TRefCountPtrArg<ZSituationMember> rMember, ZSituationOrder::EOrderClearStatus status);

	ZSituationGroup() = default;
	ZSituationGroup(STypeID* classType, const TEntityRef<ZSituationBase>& rSituation);
	void AddRef() const;
	void Release() const;
	STypeID* GetClassType() const;
	TEntityRef<ZSituationBase> GetSituation() const;
	void ActivateMember(TRefCountPtrArg<ZSituationMember> rMember);
	void DeactivateMember(TRefCountPtrArg<ZSituationMember> rMember);
	TMaxArray<TRefCountPtr<ZSituationMember>, 8>& Actors();
	void AssignOrder(TRefCountPtrArg<ZSituationMember> rMember, TRefCountPtrArg<ZSituationOrder> pOrder);
	void AssignPendingOrder(TRefCountPtrArg<ZSituationMember> rMember, TRefCountPtrArg<ZSituationOrder> pOrder);
	void InvalidateOrder(TRefCountPtrArg<ZSituationMember> rMember);
	void ClearPendingOrder(TRefCountPtrArg<ZSituationMember> rMember);
	bool TryAssignCallOnRadioActOrder(TRefCountPtr<ZActorDialog> pDialog, TRefCountPtrArg<ZSituationMember> pMemberSpeaker);
	bool IsDialogCompleted(TRefCountPtrArg<ZActorDialog> pDialog);
	bool IsDialogEntryCompleted(TRefCountPtrArg<ZActorDialog> pDialog, int nEntry);
	bool IsLastSpeakTriggered(TRefCountPtrArg<ZActorDialog> pDialog);
	TRefCountPtr<ZActorDialog> StartDialog(SActorSoundDefs::EDefinition eSound, TRefCountPtrArg<ZSituationMember> rMember, SActorSoundDefs::EDefinition eResponseSound, TRefCountPtrArg<ZSituationMember> rResponder);
	TRefCountPtr<ZActorDialog> StartDialog(SActorSoundDefs::EDefinition eSound, TRefCountPtrArg<ZSituationMember> rMember);
	bool AddDialogEntry(TRefCountPtrArg<ZActorDialog> pDialog, SActorSoundDefs::EDefinition eSound, TRefCountPtrArg<ZSituationMember> rMember);
	void InterruptDialog(TRefCountPtrArg<ZActorDialog> pDialog, bool bStopSpeak);
	bool CheckNaughtyHitman(TRefCountPtrArg<ZSituationMember> pMember, ZSharedKnowledgeRef pTarget);
	void OnSituationDeleted();
};
