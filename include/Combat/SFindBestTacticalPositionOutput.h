#pragma once

#include "ZGridNodeRef.h"

class alignas(4) SFindBestTacticalPositionOutput
{
public:
    ZGridNodeRef m_node;
    float m_fRating;
    bool m_bValid;
};
