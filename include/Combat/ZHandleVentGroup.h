#pragma once

#include "ZSituationGroup.h"
#include "ZCombatSituationMember.h"
#include "ZGridJobRequest.h"

class ZHandleVentGroup : public ZSituationGroup
{
public:
	TRefCountPtr<ZCombatSituationMember> m_pProcessingMember;
	ZGridJobRequest<ZGridNodeRef> m_bestNodeRequest;
	ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_distanceFieldRequest;
	TMaxArray<ZGridNodeRef, 128> m_blockedNodes;
	ZGameTime m_targetNotVisibleStartTime;
	ZGameTime m_lastFireDialogTime;
	TRefCountPtr<ZActorDialog> m_pDialog;
	bool m_bNoStanddown;

	~ZHandleVentGroup() override = default;
	void OnMemberDeactivated(TRefCountPtrArg<ZSituationMember> rMember) override;

	ZHandleVentGroup() = default;
	ZHandleVentGroup(const TEntityRef<ZSituationBase>& rSituation, TRefCountPtrArg<ZCombatSituationMember> pInitialMember, bool bNoStanddown);
	bool AddAssistant(TRefCountPtrArg<ZCombatSituationMember> rMember);
	bool Update(const ZGridNodeRef& lastKnownTargetNode, const TRefCountPtr<ZGridFloatField>& distanceFieldFromTarget);
};
