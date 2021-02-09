#pragma once

#include "SClosestActorInfo.h"
#include "SActorCounts.h"

class alignas(8) ZAIGameState
{
public:
    SClosestActorInfo m_ActorInfo;
    float m_fDisguiseHealth;
    TEntityRef<IHM5Outfit> m_pCurrentOutfit;
    SActorCounts m_ActorCounts;
    EGameTension m_eGameTension;
    EGameTension m_eGameTensionGuard;
    EGameTension m_eGameTensionCivilian;
    int m_nAliveEnemyCount;
    int m_nAliveGuardCount;
    ZGameTime m_nLastBulletFlyByEventTime;
    float m_fAttentionMax;
    float m_fAttentionMaxPan;
    TEntityRef<ZActor> m_pAttentionMaxActor;
    float m_fTrespassingAttentionMax;
    float m_fTrespassingAttentionMaxPan;
    TEntityRef<ZActor> m_pTrespassingAttentionMaxActor;
    float m_fDisguiseAttentionMax;
    float m_fDisguiseAttentionMaxPan;
    TEntityRef<ZActor> m_pDisguiseAttentionMaxActor;
    float m_fDisguiseHeat;
    float m_fDisguiseHeatPan;
    bool m_bDisguiseSameOutfit;
    int m_nDisguiseHeatRating;
    TEntityRef<ZActor> m_pDisguiseHeatActor;
    ZGameTime m_tLastCiviliansGotHelpEvent;
    
    union
    {
        unsigned int unionInt;
        
        struct
        {
            __int8 m_bOutfitBroken : 1;
            __int8 m_bOutfitSuspicious : 1;
            __int8 m_bInDisguise : 1;
            __int8 m_bHitmanInCombat : 1;
            __int8 m_bBulletFlyBy : 1;
            __int8 m_bIsHitmanStealthKilling : 1;
            __int8 m_bHitmanTrespassing : 1;
            __int8 m_bHitmanDeepTrespassing : 1;
            __int8 m_bHitmanNearDeadBody : 1;
            __int8 m_bHitmanIllegalWeapon : 1;
            __int8 m_bHitmanChangingOutfit : 1;
            __int8 m_bAttentionOSDVisible : 1;
            __int8 m_bBodyFound : 1;
            __int8 m_bBloodPoolFound : 1;
            __int8 m_bCanOpenCPDoor : 1;
            __int8 m_bIsHitmanHunted : 1;
            __int8 m_bSpottedEnteringCloset : 1;
            __int8 m_bAnyGuardsAlive : 1;
        };
    };
};
