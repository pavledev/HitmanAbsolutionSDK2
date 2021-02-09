#pragma once

#include "ZSituationGroup.h"
#include "ZCombatSituationMember.h"
#include "EHandleClosetSpeechState.h"

class ZHandleClosetGroup : public ZSituationGroup
{
public:
    TRefCountPtr<ZCombatSituationMember> m_pProcessingMember;
    ZGridJobRequest<ZGridNodeRef> m_bestNodeRequest;
    ZGridJobRequest<TRefCountPtr<ZGridFloatField> > m_distanceFieldRequest;
    TMaxArray<ZGridNodeRef, 128> m_blockedNodes;
    ZGameTime m_startTime;
    TRefCountPtr<ZActorDialog> m_pDialog;
    EHandleClosetSpeechState m_SpeechState;
};
