#pragma once

#include "SMatrix.h"
#include "ZEntityRef.h"
#include "ECCEmitterEffect.h"
#include "TEntityRef.h"
#include "ZHM5BaseCharacter.h"
#include "ZCrowdActor.h"

class SCCEffect
{
public:
    float m_fEffectTime;
    int m_nBoneGlobalID;
    SMatrix m_mEmitterLocal;
    ZEntityRef m_rEffect;
    ECCEmitterEffect m_eEffect;
    TEntityRef<ZHM5BaseCharacter> m_rBaseChar;
    TEntityRef<ZCrowdActor> m_pCrowdActor;
    bool m_bActive;
    TResourcePtr<IEntityBlueprintFactory> m_pBlueprintResource;
};
