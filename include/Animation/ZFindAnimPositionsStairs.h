#pragma once

#include "SMatrix.h"
#include "SAnimSample.h"
#include "ZPF5Location.h"
#include "SVector2.h"
#include "ZPF5LineHitInfo.h"
#include "ZPathfinder2.h"

class alignas(16) ZFindAnimPositionsStairs
{
public:
    SMatrix m_mAnimSample1;
    SAnimSample m_AnimSample[2];
    ZPF5Location m_PFLocMid;
    bool m_bSolved;
    int m_nNumIter;
    float m_fTimeSpent;
    int m_nCompNorm;
    float4 m_vTraceLength;
    float m_fLengthContrainAnim;
    SVector2 m_vCollisionNormal;
    float m_fCollisionOffset;
    bool m_abCollision[2];
    float4 m_avEndPoints[2];
    ZPF5LineHitInfo m_aLineHitInfo[2];
    float4 m_vTraceDir;
    ZPathfinder2* m_pPathfinder;

    struct GetValidNormal
    {
        struct __l5
        {
            struct SCompLevel
            {
                int m_nComp;
                unsigned int m_nLevel;
            };
        };
    };
};
