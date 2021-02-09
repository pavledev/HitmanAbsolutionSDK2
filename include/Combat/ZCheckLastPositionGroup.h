#pragma once

#include "ZSituationGroup.h"
#include "ZCombatSituationMember.h"

class alignas(8) ZCheckLastPositionGroup : public ZSituationGroup
{
public:
    TRefCountPtr<ZCombatSituationMember> m_pLeader;
    TRefCountPtr<ZCombatSituationMember> m_pAssistant;
    ZGridJobRequest<ZGridNodeRef> m_leaderBestNodeRequest;
    ZGridJobRequest<ZGridNodeRef> m_assistantBestNodeRequest;
    ZGridJobRequest<TRefCountPtr<ZGridFloatField> > m_leaderDistanceFieldRequest;
    ZGridJobRequest<TRefCountPtr<ZGridFloatField> > m_assistantDistanceFieldRequest;
    ZGridNodeRef m_leaderTargetNode;
    TRefCountPtr<ZActorDialog> m_pDialog;
    bool m_bLeaderOrderAssigned;
    bool m_bAssistantOrderAssigned;
    bool m_bSearchCompleted;
};
