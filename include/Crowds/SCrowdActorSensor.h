#pragma once

#include "SVector2.h"

struct SCrowdActorSensor
{
    __int16 m_aCurrentNeighbors[21];
    unsigned __int8 m_nCurNumNeighbors;
    unsigned __int8 m_nWorstThreat;
    float m_nTimeToCollision;
    float m_nDistanceToWall;
    SVector2 m_vWallNormal;
    float m_nObstacleDensity;
};
