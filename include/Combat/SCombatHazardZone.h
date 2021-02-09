#pragma once

#include "float4.h"

class alignas(16) SCombatHazardZone
{
public:
    float4 m_wsPosition;
    float m_fRadius;
    float m_fTime;
};
