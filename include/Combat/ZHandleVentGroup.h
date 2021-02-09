#pragma once

#include "ZSituationGroup.h"
#include "ZCombatSituationMember.h"

class alignas(8) ZHandleVentGroup : public ZSituationGroup
{
public:
    TRefCountPtr<ZCombatSituationMember> m_pProcessingMember;
    ZGridJobRequest<ZGridNodeRef> m_bestNodeRequest;
    ZGridJobRequest<TRefCountPtr<ZGridFloatField> > m_distanceFieldRequest;
    TMaxArray<ZGridNodeRef, 128> m_blockedNodes;
    ZGameTime m_targetNotVisibleStartTime;
    ZGameTime m_lastFireDialogTime;
    TRefCountPtr<ZActorDialog> m_pDialog;
    bool m_bNoStanddown;
};
