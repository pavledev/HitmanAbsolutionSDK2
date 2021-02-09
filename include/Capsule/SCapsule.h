#pragma once

#include "float4.h"

class alignas(16) SCapsule
{
public:
    float4 m_vBottom;
    float4 m_vTop;
    float m_fRadius;
};
