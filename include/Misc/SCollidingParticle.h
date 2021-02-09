#pragma once

#include "float4.h"

struct alignas(16) SCollidingParticle
{
    float4 m_vPosition;
    float4 m_vVelocity;
    unsigned int m_nColor;
    float m_fSize;
};
