#pragma once

#include "float4.h"
#include "ZEntityRef.h"
#include "TEntityRef.h"
#include "ZCrowdActor.h"
#include "SRayInfo.h"

class ZHM5SBTag
{
public:
    float4 m_vShotPos;
    unsigned int m_nTargetBone;
    float m_fTagTimeFraction;
    float m_fTime;
    float m_fDamageDealt;
    ZEntityRef m_rEntity;
    TEntityRef<ZCrowdActor> m_pCrowdActor;
    __int8 m_bKillingShot : 1;
    __int8 m_bKillConfirmed : 1;
    __int8 m_bShot : 1;
    __int8 m_bActorTag : 1;
    __int8 m_bDead : 1;
    __int8 m_bExplodingProp : 1;
    __int8 m_bActorUntaggable : 1;
    __int8 m_bHasHitThroughChainReaction : 1;
    __int8 m_bShowTag : 1;
    float m_fLocalBoneHeight;
    SRayInfo m_rayInfo;
};
