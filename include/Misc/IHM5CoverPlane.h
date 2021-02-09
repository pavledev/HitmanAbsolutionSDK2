#pragma once

#include "IComponentInterface.h"
#include "ZSpatialEntity.h"

class IHM5CoverPlane : public IComponentInterface
{
public:
    virtual float GetCoverDepth();
    virtual bool IsHighCover();
    virtual bool IsMediumCover();
    virtual bool IsLowCover();
    virtual float GetCoverLength();
    virtual ZSpatialEntity* GetNeighborCoverPlane(const float4*, float4*);
    virtual float GetCoverHeight();
    virtual float4* GetCoverDir(float4* result);
    virtual bool IsWindowCover();
};
