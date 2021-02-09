#pragma once

#include "float4.h"
#include "ZPF5Location.h"

class SAnimCollision
{
public:
    float4 m_vEdgeVertex0;
    float4 m_vEdgeVertex1;
    float4 m_vNormal;
    float m_fTranslation;
    alignas(16) ZPF5Location m_PF5Collision;
    bool m_bGround;
    bool m_bCollision;
};
