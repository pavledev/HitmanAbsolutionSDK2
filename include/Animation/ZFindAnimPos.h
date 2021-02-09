#pragma once

#include "ZPathfinder2.h"
#include "SAnimSample.h"
#include "SMatrix33.h"
#include "SAnimCollision.h"

class ZFindAnimPos
{
public:
    ZPathfinder2* m_pPathfinder;
    SAnimSample m_AnimSample;
    ZFindAnimPos* m_pAnimPosConstrain;
    SMatrix33 m_mRotContrainAnim;
    float m_fLengthContrainAnim;
    alignas(8) ZPF5Location m_PF5Location;
    float4 m_vStartPos;
    unsigned __int16 m_nAllowMask;
    SAnimCollision m_AnimCollision;
};
