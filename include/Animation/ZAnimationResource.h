#pragma once

#include "ZRuntimeResourceID.h"
#include "SMatrix43.h"
#include "ZFoVAnimation.h"
#include "ZAnimatedBoneScales.h"
#include "MR.h"

class ZAnimationResource
{
public:
    ZAnimationResource* m_pNext;
    ZAnimationResource* m_pPrevious;
    ZRuntimeResourceID m_ridResource;
    SMatrix43 m_sequenceOrigin;
    ZFoVAnimation* m_pFoVAnimation;
    ZAnimatedBoneScales* m_pAnimatedBoneScales;
    MR::IAnimSource* m_pAnimationSource;
    MR::RigToAnimMap* m_pRigToAnimMap;
    MR::EventSequenceHeader* m_pEventSequenceHeader;
    MR::Rig* m_pRig;
};
