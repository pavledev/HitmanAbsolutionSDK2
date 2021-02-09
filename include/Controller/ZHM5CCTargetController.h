#pragma once

#include "float4.h"
#include "SHM5CCTarget.h"
#include "ZHitman5.h"
#include "ZPF5Location.h"

class ZHM5CCTargetController
{
public:
    bool m_bAllowAttacks;
    float4 m_vMainDir;
    float4 m_vMainPos;
    SHM5CCTarget m_TargetPos[4];
    SHM5CCTarget m_RunInTargetInfo[3];
    TEntityRef<ZHitman5> m_pHitman;
    alignas(16) ZPF5Location m_StartLocation;
    bool m_bLock;

    struct STargetPositions
    {
        ECCTargetPos m_eFirstPos;
        ECCTargetPos m_eSecondPos;
    };
};
