#pragma once

#include "ZAnimationBoneData.h"
#include "ZAnimationBonePose.h"
#include "SMatrix.h"
#include "SBoneAnimatorInfo.h"

class IBoneAnimator
{
public:
    virtual ~IBoneAnimator();
    virtual void UpdateBones(const ZAnimationBoneData*, ZAnimationBonePose*, const SMatrix*, const SMatrix*);
    virtual bool TryCalculateBounds(float4*, float4*, const float4*, const float4*, const ZAnimationBoneData*);
    virtual void SetBoneAnimatorInfo(const SBoneAnimatorInfo*);
};
