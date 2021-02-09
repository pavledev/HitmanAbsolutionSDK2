#pragma once

#include "float4.h"

class alignas(16) SSphere
{
public:
    float4 m_vCenter;
    float m_fRadius;
};
