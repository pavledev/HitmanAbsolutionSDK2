#pragma once

#include "float4.h"

class alignas(16) SCheckedPos
{
public:
    float4 m_vPos;
    bool m_bSafe;
};
