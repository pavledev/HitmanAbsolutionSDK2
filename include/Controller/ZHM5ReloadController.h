#pragma once

#include "TEntityRef.h"
#include "IHM5ItemWeapon.h"
#include "IMorphemeEntity.h"
#include "ZHitmanMorphemePostProcessor.h"
#include "ZHitman5.h"

class alignas(4) ZHM5ReloadController
{
public:
    TEntityRef<IHM5ItemWeapon> m_rWeaponToReload[2];
    TEntityRef<IMorphemeEntity> m_MorphemeEntity;
    ZMorphemeNetworkInstance* m_pMrNetwork;
    ZHitmanMorphemePostProcessor* m_PostProcessor;
    TEntityRef<ZHitman5> m_pHitman;
    bool m_bProgressReloadFraction;
    bool m_bSkipToCockingSection;
    alignas(4) float m_fReloadWeight;
    float m_fReloadAnimFraction;
    float m_fReloadFirstShellFraction;
    float m_fReloadRepeatFraction;
    float m_fReloadCockingFraction;
    float m_fReloadLoopTarget;
    float m_fAnimDuration;
    float m_fReloadTechniqueFactor;
    unsigned int m_nReloadAnimID;
    
    union
    {
        unsigned __int8 unionInt;
        
        struct
        {
            __int8 m_bReloading : 1;
            __int8 m_bReloadQueued : 1;
            __int8 m_bAborted : 1;
            __int8 m_bCanStartToReload : 1;
        };
    };
};
