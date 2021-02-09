#pragma once

#include "SCameraCollision.h"

class ZHM5CameraColi
{
    SCameraCollision m_ColiInfo[5];
    float m_fColiLength;
    bool m_bColi;
    float m_fDistWall;
    int m_iCurColi;
    int m_iClosestColi;
    float4 m_vRatioDistanceToWall;
};
