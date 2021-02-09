#pragma once

#include "float4.h"

class SSoftCollisionCache
{
public:
    float4 m_avSoftCollisions[16];
    int m_nNumSoftCollisions;
    bool m_bGotContactPoint;
    float4 m_vContactPoint;
};
