#pragma once

#include "ZItemLegend.h"

class ZHM5CoverPlane;

class alignas(4) sNeighbourInfo
{
public:
    ZHM5CoverPlane* m_pNPlane;
    float m_fAngle;
    ZItemLegend::EInputDevice m_NState;
    __int8 m_bConvex : 1;
};
