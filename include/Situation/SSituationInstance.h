#pragma once

#include "TEntityRef.h"
#include "ESituationType.h"
#include "ZSituationMember.h"

class ZSituationBase;

class alignas(8) SSituationInstance
{
public:
    TEntityRef<ZSituationBase> m_pSituation;
    ZSharedKnowledgeRef m_pSituationShared;
    ZSharedKnowledgeRef m_pTargetShared;
    ZEntityRef m_pTarget;
    ESituationType m_type;
    int m_nPhase;
    ZGameTime m_phaseStartTime;
    ZGameTime m_situationStartTime;
    TMaxArray<TRefCountPtr<ZSituationMember>, 64> m_actors;
    TMaxArray<ZSituationGroup*, 32> m_groups;
    bool m_bSituationEnded;
};
