#pragma once

#include "CrowdUtil.h"

class ZCrowdActor;
class ZDebugRender;
struct SMatrix;
struct float4;
template <class T> class TEntityRef;

class __declspec(novtable) ZCrowdActorState
{
public:
	virtual ~ZCrowdActorState() = default;
	virtual void UpdateActor(TEntityRef<ZCrowdActor> entityRef, float param2) = 0;
	virtual void UpdateState(float nDt);
	virtual bool EnterState(TEntityRef<ZCrowdActor> entityRef, ZCrowdActorState* crowdActorState) = 0;
	virtual bool WantExitState(TEntityRef<ZCrowdActor> pActor, int* pNextStateIndex);
	virtual CrowdUtil::ECrowdActorMood GetStateMood() const = 0;
	virtual bool CanRandomStopHere(TEntityRef<ZCrowdActor> pActor);
	virtual bool CollidesWithHitman(const TEntityRef<ZCrowdActor> pActor);
	virtual int GetStateIndex() const;
	virtual unsigned int GetDebugColor() const;
	virtual void DrawDebug(TEntityRef<ZCrowdActor> pActor, ZDebugRender* pDebugRender, const SMatrix& mWorldMatrix, const float4& vLocalPosOffset, const float4& vDebugGfxOffset);

	ZCrowdActorState() = default;
};
