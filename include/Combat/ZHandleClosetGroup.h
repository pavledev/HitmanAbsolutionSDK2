#pragma once

#include "ZSituationGroup.h"
#include "ZCombatSituationMember.h"
#include "EHandleClosetSpeechState.h"
#include "ZGridJobRequest.h"

class ZHandleClosetGroup : public ZSituationGroup
{
public:
	TRefCountPtr<ZCombatSituationMember> m_pProcessingMember;
	ZGridJobRequest<ZGridNodeRef> m_bestNodeRequest;
	ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_distanceFieldRequest;
	TMaxArray<ZGridNodeRef, 128> m_blockedNodes;
	ZGameTime m_startTime;
	TRefCountPtr<ZActorDialog> m_pDialog;
	EHandleClosetSpeechState m_SpeechState;

	~ZHandleClosetGroup() override = default;
	void OnMemberDeactivated(TRefCountPtrArg<ZSituationMember> rMember) override;

	ZHandleClosetGroup() = default;
	ZHandleClosetGroup(const TEntityRef<ZSituationBase>& rSituation, TRefCountPtrArg<ZCombatSituationMember> pInitialMember, bool bPlayDialog);
	bool AddAssistant(TRefCountPtrArg<ZCombatSituationMember> rMember);
	bool Update(const ZGridNodeRef& lastKnownTargetNode, const TRefCountPtr<ZGridFloatField>& distanceFieldFromTarget);
	void NextSpeak();
};
