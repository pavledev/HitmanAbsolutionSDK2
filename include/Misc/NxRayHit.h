#pragma once

#include "NxScene.h"

class NxRayHit
{
public:
    NxShape* m_pShape;
    float m_nT;
    NxVec3 m_vPosition;
    NxVec3 m_vNormal;
};
