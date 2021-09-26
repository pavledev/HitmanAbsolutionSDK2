#pragma once

#include "ZEntityImpl.h"
#include "INodeRatingDebug.h"
#include "TRefCountPtr.h"
#include "ZGridJobRequest.h"
#include "ESituationJoinReason.h"
#include "ZSituationOrder.h"
#include "SActorSoundDefs.h"
#include "ESituationType.h"
#include "EActorType.h"
#include "SComponentMapEntry.h"
#include "ZGameTime.h"
#include "ZGridNodeRef.h"
#include "ZVariantRef.h"

struct SPropagationInfo;
class ZSituationMember;
class ZSituationGroup;
struct SSituationInstance;
class ZActorDialog;
class ZActor;
class ZSharedKnowledgeRef;
struct SKnownEntity;
struct SGameUpdateEvent;
class ZComponentCreateInfo;
class ZGridFloatField;
struct STypeID;
template <class A, int B> class TMaxArray;
template <class T> class TArrayRef;
template <class T> class TEntityRef;
template <class T> class TRefCountPtrArg;

class __declspec(novtable) ZSituationBase : public ZEntityImpl, public INodeRatingDebug
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	SSituationInstance* m_pInstance;
	int m_nLOSPropagationMemberIndex;
	TRefCountPtr<ZSituationMember> m_pLOSPropagationMember;
	int m_nPropagationMemberIndex;
	TRefCountPtr<ZSituationMember> m_pPropagationMember;
	ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_propagationRequest;
	ZGameTime m_tPropagationStartTime;
	int m_nNextGroupID;

	static SComponentMapEntry s_componentMap[0];

	~ZSituationBase() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	virtual bool CanJoin(const TEntityRef<ZActor>& pActor, const ZSharedKnowledgeRef& rTarget) const;
	virtual void OnSituationStarted();
	virtual void OnSituationEnded();
	virtual TRefCountPtr<ZSituationMember> OnActorJoin(const TEntityRef<ZActor>& entityRef, const TRefCountPtr<SKnownEntity>& refCountPtr, ESituationJoinReason situationJoinReason) = 0;
	virtual void OnActorJoined(TRefCountPtrArg<ZSituationMember> pMember, const TRefCountPtr<SKnownEntity>& rTarget, ESituationJoinReason eReason);
	virtual void OnActorLeave(TRefCountPtrArg<ZSituationMember> pMember);
	virtual void OnUpdate(const SGameUpdateEvent& updateEvent);
	virtual void OnOrderClear(TRefCountPtrArg<ZSituationMember> pMember, ZSituationOrder::EOrderClearStatus status);
	virtual bool CanMemberSpeak(TRefCountPtrArg<ZSituationMember> rMember, SActorSoundDefs::EDefinition eSound);

	float GetNodeDebugRating(const ZGridNodeRef& nodeRef) override;
	float GetNodeDebugTextRatingScale() override;

	ZSituationBase() = default;
	static void RegisterType();
	ZSituationBase(ZComponentCreateInfo& info);
	void SetInstance(SSituationInstance& instance);
	ESituationType GetType() const;
	float SituationAge() const;
	ZSharedKnowledgeRef& SituationShared();
	const ZSharedKnowledgeRef& TargetShared() const;
	ZSharedKnowledgeRef& TargetShared();
	const TMaxArray<TRefCountPtr<ZSituationMember>, 64>& Actors() const;
	TMaxArray<TRefCountPtr<ZSituationMember>, 64>& Actors();
	void SetTarget(const ZSharedKnowledgeRef& newTarget);
	bool JoinSituation(const TEntityRef<ZActor>& pActor, const TRefCountPtr<SKnownEntity>& rTarget, ESituationJoinReason eReason);
	bool LeaveSituation(const TEntityRef<ZActor>& pActor);
	void RemoveAllActors();
	TRefCountPtr<ZSituationMember> FindMember(const TEntityRef<ZActor>& pActor);
	void CompleteOrder(TRefCountPtrArg<ZSituationMember> pMember);
	void AbandonOrder(TRefCountPtrArg<ZSituationMember> pMember);
	void FailOrder(TRefCountPtrArg<ZSituationMember> pMember);
	int NextGroupID();
	void OnAttachGroup(ZSituationGroup* pGroup);
	void OnDetachGroup(ZSituationGroup* pGroup);
	void AssignOrder(TRefCountPtrArg<ZSituationMember> pMember, TRefCountPtrArg<ZSituationOrder> pOrder, float fForceTime);
	void AssignPendingOrder(TRefCountPtrArg<ZSituationMember> pMember, TRefCountPtrArg<ZSituationOrder> pOrder, float fForceTime);
	void InvalidateOrder(TRefCountPtrArg<ZSituationMember> pMember);
	void ClearPendingOrder(TRefCountPtrArg<ZSituationMember> pMember);
	void ExpireForcedOrder(TRefCountPtrArg<ZSituationMember> pMember);
	TRefCountPtr<ZActorDialog> StartDialog(TArrayRef<SActorSoundDefs::EDefinition> sounds, const TMaxArray<TRefCountPtr<ZSituationMember>, 64>& speakerCandidates, const ZSharedKnowledgeRef& rDialogTarget);
	TRefCountPtr<ZActorDialog> StartDialog(SActorSoundDefs::EDefinition eSound, const TMaxArray<TRefCountPtr<ZSituationMember>, 64>& speakerCandidates, const ZSharedKnowledgeRef& rDialogTarget);
	TRefCountPtr<ZActorDialog> StartDialog(SActorSoundDefs::EDefinition eSound, TRefCountPtrArg<ZSituationMember> rMember, SActorSoundDefs::EDefinition eResponseSound, TRefCountPtrArg<ZSituationMember> rResponder);
	TRefCountPtr<ZActorDialog> StartDialog(SActorSoundDefs::EDefinition eSound, TRefCountPtrArg<ZSituationMember> rMember);
	bool AddDialogEntry(TRefCountPtrArg<ZActorDialog> pDialog, SActorSoundDefs::EDefinition eSound, TRefCountPtrArg<ZSituationMember> rMember);
	void InterruptDialog(TRefCountPtrArg<ZActorDialog> pDialog, bool bStopSpeak);
	bool IsDialogCompleted(TRefCountPtrArg<ZActorDialog> pDialog);
	bool TryAssignCallOnRadioActOrder(TRefCountPtr<ZActorDialog> pDialog, TRefCountPtrArg<ZSituationMember> pMemberSpeaker);
	void SortMembersFromFloatField(TRefCountPtrArg<ZGridFloatField> field, TMaxArray<TRefCountPtr<ZSituationMember>, 64>& result, bool bAscending);
	TRefCountPtr<ZSituationMember> FindMinMemberFromFloatField(TRefCountPtrArg<ZGridFloatField> field, float fMaxValue, EActorType type);
	TRefCountPtr<ZSituationMember> FindMaxMemberFromFloatField(TRefCountPtrArg<ZGridFloatField> field, float fMinValue, EActorType type);
	bool CheckNaughtyHitman(TRefCountPtrArg<ZSituationMember> pMember, ZSharedKnowledgeRef pTarget);
	bool CheckActorPropagation(const SPropagationInfo& infoGuard, const SPropagationInfo& infoCivilian, TEntityRef<ZActor>& rResult, TRefCountPtr<ZSituationMember>& pPropagatedFrom, bool bSpread);
};
