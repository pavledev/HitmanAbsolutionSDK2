#pragma once

#include "SMatrix.h"
#include "float4.h"

class alignas(16) sLedgeHangInfos
{
public:
    SMatrix m_mvAttacher[2];
    SMatrix m_mvAttacherTarget[2];
    float4 m_vHandDir[2];
    float4 m_PelvisPushDir;
    float m_fHandWeight[2];
    bool m_bValid;
};
