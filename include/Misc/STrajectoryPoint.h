#pragma once

#include "float4.h"

class alignas(16) STrajectoryPoint
{
public:
    float4 m_vPos;
    float m_fTime;
};
