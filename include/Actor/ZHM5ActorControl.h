#pragma once

#include "float4.h"
#include "TList.h"
#include "SNearEnemyCheckReq.h"

class ZHitman5;

class alignas(16) ZHM5ActorControl
{
public:
    float4 m_vClipPlanes[6];
    TList<SNearEnemyCheckReq> m_NearEnemyChecks;
    TEntityRef<ZActor> m_pNearestEnemy;
    TEntityRef<ZActor> m_pNearestDeadActor;
    TEntityRef<ZActor> m_pNearestOutfitActor;
    TEntityRef<ZCrowdActor> m_pNearestCrowdActor;
    TEntityRef<ZCrowdActor> m_pMostFacingNearCrowdActor;
    TEntityRef<ZCrowdActor> m_pNearestBackfacingCrowdActor;
    TEntityRef<ZHitman5> m_pHitman;

    enum UnkEnum : __int32
    {
        CLIPPLANESNUM = 0x6
    };
};
