#pragma once

#include "ZPF5Location.h"

class alignas(16) ZPF5LineHitInfo
{
public:
    ZPF5Location m_PF5Location;
    SVector3 m_vEdgeVertex0;
    SVector3 m_vEdgeVertex1;
};
