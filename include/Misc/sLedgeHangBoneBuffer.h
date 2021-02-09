#pragma once

#include "SQV.h"

class sLedgeHangBoneBuffer
{
public:
    bool m_bValid;
    SQV m_Bones[13];
    int m_nBoneIds[13];
    float4 m_vPelvisPushDir;
};
