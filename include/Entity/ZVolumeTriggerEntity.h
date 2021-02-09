#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZSpatialEntity.h"

class alignas(4) ZVolumeTriggerEntity : ZEntityImpl
{
    TArray<TEntityRef<ZSpatialEntity> > m_Spatials;
    bool m_bEnabled;
    bool m_TypeHitman;
    bool m_TypeActorAlive;
    bool m_TypeActorDead;
    bool m_TypeExplodeableItem;
    ZEntityRef m_pOwner;
    unsigned int m_nTypeFlags;
    __int8 m_bActivated : 1;
    __int8 m_bColliding : 1;
    __int8 m_bRegistered : 1;
};
