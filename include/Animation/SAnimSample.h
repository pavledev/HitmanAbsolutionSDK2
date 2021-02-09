#pragma once

#include "float4.h"

class SAnimSample
{
public:
    unsigned int m_iNumPoints;
    unsigned int m_iNumSamples;
    float4 m_avPoints[64];
    bool m_abOwnPoint[64];
};
