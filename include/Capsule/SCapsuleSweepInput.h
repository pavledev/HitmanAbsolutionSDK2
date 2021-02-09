#pragma once

#include "float4.h"
#include "ECollidablesType.h"

class alignas(16) SCapsuleSweepInput
{
public:
    float4 m_vOrigin;
    float4 m_vCapsEndPoint;
    float4 m_vTo;
    float m_fRadius;
    unsigned int m_nFilter;
    ECollidablesType m_eType;
};
