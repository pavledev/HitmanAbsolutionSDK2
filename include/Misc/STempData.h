#pragma once

#include "float4.h"

struct alignas(16) STempData
{
    float4 m_vPos;
    float m_fVolume;
    float m_fPitchMultiplier;
    float m_fStartOffset;
    bool m_bIs3D;
    int m_nLoopCount;
    int m_nChannelMode;
};
