#pragma once

#include "TEntityRef.h"
#include "SMatrix.h"

class ZCrowdActor;

class ZCrowdActorState
{
public:
    virtual ~ZCrowdActorState();
    virtual void UpdateActor(TEntityRef<ZCrowdActor>, float);
    virtual void UpdateState(float);
    virtual bool EnterState(TEntityRef<ZCrowdActor>, ZCrowdActorState*);
    virtual bool WantExitState(TEntityRef<ZCrowdActor>, int*);
    virtual CrowdUtil::ECrowdActorMood GetStateMood();
    virtual bool CanRandomStopHere(TEntityRef<ZCrowdActor>);
    virtual bool CollidesWithHitman(const TEntityRef<ZCrowdActor>);
    virtual int GetStateIndex();
    virtual unsigned int GetDebugColor();
    virtual void DrawDebug(TEntityRef<ZCrowdActor>, struct ZDebugRender*, const SMatrix*, const float4*, const float4*);
};
