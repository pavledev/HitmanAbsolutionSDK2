#pragma once

#include "ZGameTime.h"
#include "TEntityRef.h"
#include "ZSituationOrder.h"
#include "ZSituationGroup.h"

class ZSituationBase;

class ZSituationMember
{
public:
    alignas(8) int m_nRefCount;
    ZGameTime m_tJoinedTime;
    TEntityRef<ZSituationBase> m_rSituation;
    ZSituationGroup* m_pActiveGroup;
    TRefCountPtr<ZSituationOrder> m_pCurrentOrder;
    bool m_bCurrentOrderValid;
    ZGameTime m_tCurrentOrderStart;
    float m_fCurrentOrderForceTime;
    TRefCountPtr<ZSituationOrder> m_pPendingOrder;
    float m_fPendingOrderForceTime;
    TEntityRef<ZActor> m_pActor;
    TRefCountPtr<SKnownEntity> m_rKnownTarget;

    virtual ~ZSituationMember();
    virtual void OnOrderAssigned();
};
