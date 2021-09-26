#pragma once

#include "ZSituationGroup.h"
#include "ZActorRelationshipEntity.h"
#include "EHumanShieldSpeechState.h"
#include "ZGridJobRequest.h"

class ZHumanShieldGroup : public ZSituationGroup
{
public:
	TRefCountPtr<ZSituationMember> m_pLeader;
	ZGameTime m_tGroupTime;
	TRefCountPtr<ZActorDialog> m_pDialog;
	TEntityRef<ZActor> m_pVictim;
	TEntityRef<ZActorRelationshipEntity> m_pRelationship;
	EHumanShieldSpeechState m_SpeechState;
	TRefCountPtr<ZGridFloatField> m_targetDistanceField;
	ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_targetDistanceFieldRequest;
	TRefCountPtr<ZGridFloatField> m_targetLOSField;
	ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_targetLOSFieldRequest;
	int m_nPositionMemberIndex;
	TRefCountPtr<ZSituationMember> m_positionRequestMember;
	ZGridJobRequest<ZGridNodeRef> m_positionRequest;
	ZGameTime m_tLastPositionRequest;
	ZGameTime m_tLastWeaponFiredTime;

	~ZHumanShieldGroup() override = default;
	void OnMemberDeactivated(TRefCountPtrArg<ZSituationMember> rMember) override;

	ZHumanShieldGroup() = default;
	ZHumanShieldGroup(const TEntityRef<ZSituationBase>& rSituation, TRefCountPtrArg<ZSituationMember> pLeader, const TEntityRef<ZActor>& rVictim, const TEntityRef<ZActorRelationshipEntity>& rRelationship);
	void AddSupportMember(TRefCountPtrArg<ZSituationMember> pSupport);
	void SetKillGoal(TEntityRef<ZActor> pActor);
	float GetAge() const;
	bool Update();
	void NextSpeak();
	void UpdatePositions();
	void FindPosition(const TRefCountPtr<ZSituationMember>& rMember, const ZGridNodeRef& rStartNode, float fMinDistance, float fMaxDistance, float fMinLOS);
};
