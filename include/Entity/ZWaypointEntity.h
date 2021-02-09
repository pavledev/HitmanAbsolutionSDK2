#pragma once

#include "ZSpatialEntity.h"
#include "IBoolCondition.h"
#include "EMovementType.h"
#include "EWaypointRotationAlignment.h"
#include "ZChildNetworkActEntity.h"

class alignas(4) ZWaypointEntity : public ZSpatialEntity, public IBoolCondition
{
public:
    TEntityRef<ZSequenceActor> m_pSequenceActor;
    EMovementType m_MovementType;
    bool m_bAlignPosition;
    EWaypointRotationAlignment m_AlignRotation;
    float m_fDelay;
    TEntityRef<ZChildNetworkActEntity> m_pAct;
    TArray<TEntityRef<ZChildNetworkActEntity> > m_Acts;
    bool m_bEnabled;
    bool m_bReachedOnNear;
    ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull> m_BoolConditionChangedEvent;
    __int8 m_bIsOccupied : 1;
    __int8 m_bPendingSkip : 1;
    __int8 m_bActivated : 1;
};
