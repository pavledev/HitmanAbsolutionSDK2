#pragma once

#include "float4.h"

class alignas(16) SShootTargetEntry
{
public:
    float4 m_wsPosition;
    int m_nBoneID;
    float4 m_csPlaneOffset;
    bool m_bValid;
};
