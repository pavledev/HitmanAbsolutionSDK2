#pragma once

#include "TBag.h"
#include "IAsyncRayHandle.h"
#include "ZGridJobRequest.h"

class ZActor;

class ZShootTargetSensor
{
public:
    class SRayCast
    {
    public:
        IAsyncRayHandle* m_pCollisionHandle;
        TEntityRef<ZActor> m_pActor;
        TEntityRef<ZLinkedEntity> m_pTarget;
        float4 m_vFrom;
        float4 m_vTo;
    };

    TBag<SRayCast, TMaxArray<SRayCast, 128>> m_rays;
    TEntityRef<ZActor> m_pAlternativeShootTargetActorBeingUpdated;
    unsigned int m_nUpdateAlternativeShootTargetIndex;
    ZGridJobRequest<ZGridNodeRef> m_alternativeShootPositionRequest;
};
