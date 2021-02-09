#pragma once

#include "ZSpatialEntity.h"
#include "ZResourcePtr.h"

class ZAgitatedWaypointEntity : public ZSpatialEntity
{
public:
    float m_fMinDelay;
    ZResourcePtr m_pGizmo;
    bool m_bHideOnStart;
    SVector3 m_vSubPosition0;
    SVector3 m_vSubPosition1;
    SVector3 m_vSubPosition2;
    float m_fSubAngle0;
    float m_fSubAngle1;
    float m_fSubAngle2;
};
