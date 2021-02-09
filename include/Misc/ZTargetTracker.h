#pragma once

#include "ZEvent.h"
#include "TEntityRef.h"
#include "ZActor.h"
#include "SActorVisibilityCheck.h"

class ZTargetTracker
{
public:
    alignas(16) ZEvent<TEntityRef<ZActor>&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> OnTargetChanged;
    float4 m_vFrustum[6];
    TArray<SActorVisibilityCheck> m_aVisibilityChecks;
    TEntityRef<ZActor> m_pCurrentTarget;
    float m_fNearDist;
    float m_fFarDist;
    bool m_bUseFarPlane;

    virtual ~ZTargetTracker();
};
