#pragma once

#include "SVector3.h"
#include "SVector2.h"
#include "SActorIndex.h"

class alignas(4) ZCrowdActorCore
{
public:
    SVector3 m_vPosition;
    SVector2 m_vForward;
    SActorIndex m_actorIndex;
    __int16 m_nNextObstacleInCellIndex;
    int m_nPackedCellData;
    float m_nSpeed;
    unsigned __int8 m_nPossessed : 1;
    unsigned __int8 m_nMood : 7;
    unsigned __int8 m_nLODAndCulledFlag;
};
