#pragma once

#include "TResourcePtr.h"
class ZAnimationResource;

class alignas(4) SCutSequenceData
{
public:
    TResourcePtr<ZAnimationResource> m_animResource;
    float m_fAnimationTime;
    float m_fCachedFrameWeight;
    bool m_bEnableAnimationScaling;
};
