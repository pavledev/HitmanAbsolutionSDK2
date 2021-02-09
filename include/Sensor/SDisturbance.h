#pragma once

#include "float4.h"
#include "ZGameTime.h"

class alignas(16) SDisturbance
{
public:
    float4 m_vPos;
    ZGameTime m_tStart;
};
