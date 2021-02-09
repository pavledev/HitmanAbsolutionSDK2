#pragma once

#include "ZSituationGroup.h"
#include "ZActorRelationshipEntity.h"
#include "EHumanShieldSpeechState.h"

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
    ZGridJobRequest<TRefCountPtr<ZGridFloatField> > m_targetDistanceFieldRequest;
    TRefCountPtr<ZGridFloatField> m_targetLOSField;
    ZGridJobRequest<TRefCountPtr<ZGridFloatField> > m_targetLOSFieldRequest;
    int m_nPositionMemberIndex;
    TRefCountPtr<ZSituationMember> m_positionRequestMember;
    ZGridJobRequest<ZGridNodeRef> m_positionRequest;
    ZGameTime m_tLastPositionRequest;
    ZGameTime m_tLastWeaponFiredTime;
};
