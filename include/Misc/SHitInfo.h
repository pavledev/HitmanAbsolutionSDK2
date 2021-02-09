#pragma once

#include "ZEntityRef.h"
#include "ZPhysicsObjectRef.h"
#include "IProjectile.h"
#include "float4.h"
#include "SExplodeInfo.h"

class alignas(16) SHitInfo
{
public:
    ZEntityRef m_HitEntity;
    ZPhysicsObjectRef m_pHitBody;
    unsigned int m_nHitBoneIndex;
    IProjectile* m_pProjectile;
    float4 m_vHitPos;
    float4 m_vHitNormal;
    SExplodeInfo m_Explosion;
    unsigned int m_nActorDeathType;
    __int8 m_bHitmanPreciseAim : 1;
    __int8 m_bHitmanBlindShot : 1;
    __int8 m_bHitmanSnipershot : 1;
    IProjectile* m_pChainReactionProjectile;
};
