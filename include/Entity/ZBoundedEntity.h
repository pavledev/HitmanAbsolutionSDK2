#pragma once

#include "ZSpatialEntity.h"

class ZBoundedEntity : public ZSpatialEntity
{
public:
    SVector3 m_vCenter;
    SVector3 m_vHalfSize;

    virtual void UpdateBounds();
};
