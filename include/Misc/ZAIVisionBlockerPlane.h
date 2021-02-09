#pragma once

#include "ZBoundedEntity.h"

class ZAIVisionBlockerPlane : public ZBoundedEntity
{
public:
    bool m_bEnabled;
    SVector3 m_vPortalSize;
    SMatrix m_world;
};
