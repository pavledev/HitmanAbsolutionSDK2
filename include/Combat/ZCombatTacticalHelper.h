#pragma once

#include "ZGridNodeRef.h"
#include "ZHM5CoverPlane.h"
#include "ZGridJobRequest.h"
#include "ZGridFloatField.h"
#include "TMaxArray.h"
#include "ZGridByteField.h"
#include "ZCombatSituationMember.h"

class ZCombatTacticalHelper
{
public:
    alignas(16) ZGridNodeRef m_threatNode;
    float4 m_wsThreatPosition;
    ZHM5CoverPlane* m_pThreatCover;
    ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_distanceFieldRequest;
    TRefCountPtr<ZGridFloatField> m_distanceFieldFromTarget;
    ZGameTime m_distanceFieldLastUpdate;
    TMaxArray<ZGridJobRequest<TRefCountPtr<ZGridByteField>>, 32> m_hazardZoneRequests;
    TRefCountPtr<ZGridByteField> m_hazardZoneField;
    TMaxArray<ZGridJobRequest<TRefCountPtr<ZGridByteField>>, 32> m_guardPointRequests;
    TRefCountPtr<ZGridByteField> m_guardPointField;
    ZGameTime m_tLastGuardPointUpdateTime;
    ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_occupancyFieldRequest;
    TRefCountPtr<ZGridFloatField> m_occupancyField;
    TArray<TMaxArray<ZHM5CoverPlane*, 4>> m_coversForNode;
    ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_coverFieldRequest;
    TRefCountPtr<ZGridFloatField> m_coverField;
    ZGridJobRequest<ZGridNodeRef> m_bestTacticalPositionRequest;
    TRefCountPtr<ZCombatSituationMember> m_pMemberBeingUpdated;
    unsigned int m_nCurrentMemberUpdateIndex;

    virtual ~ZCombatTacticalHelper();
};
