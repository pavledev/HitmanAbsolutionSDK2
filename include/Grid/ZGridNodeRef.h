#pragma once

#include "SGWaypoint.h"

class alignas(4) ZGridNodeRef
{
public:
    unsigned __int16 m_nNodeIndex;
    const SGWaypoint* m_pNode;
    unsigned __int16 m_nRoomID;
};
