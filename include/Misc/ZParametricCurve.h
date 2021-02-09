#pragma once

#include "float4.h"

class alignas(16) ZParametricCurve
{
public:
    float4 m_vA;
    float4 m_vB;
    float4 m_vC;
    float4 m_vD;
    float m_fLength;
};
