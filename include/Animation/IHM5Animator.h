#pragma once

#include "IBoneAnimator.h"
#include "TEntityRef.h"
#include "ZLinkedEntity.h"
#include "ZHM5Ragdoll.h"
#include "EBoneAnimator.h"

class IHM5Animator : public IBoneAnimator
{
public:
    virtual void SetLinked(const TEntityRef<ZLinkedEntity>*);
    virtual void SetRagdoll(ZHM5Ragdoll*);
    virtual void StartPoweredRagdoll();
    virtual bool IsPoweredRagdollStopping();
    virtual void StopPoweredRagdoll(float, bool);
    virtual void SetBlending(const float*, const TArrayRef<SQV>);
    virtual EBoneAnimator GetCurrentAnimator();
    virtual void SetCurrentAnimator(EBoneAnimator);
    virtual void SetUpdateRagdollOnce();
    virtual bool IsRagdollControlled();
    virtual ZGameTime* GetLastBodyPartPoseInWorldSpace(ZGameTime* result, TArray<SQV>*);
};
