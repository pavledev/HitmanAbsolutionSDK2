#pragma once

#include "float4.h"
#include "ECollidablesType.h"

class alignas(16) SSphereSweepInput
{
public:
    float4 m_vFrom;
    float4 m_vTo;
    float m_fRadius;
    unsigned int m_nFilter;
    ECollidablesType m_eType;
};
