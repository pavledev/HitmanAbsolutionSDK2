#pragma once

#include "ZEntityImpl.h"
#include "IBoolCondition.h"
#include "ZBoxVolumeEntity.h"
#include "ZSphereVolumeEntity.h"
#include "ZVolumeTriggerEntity.h"
#include "ISoundPlayable.h"

class ZVolumeTriggerListenerEntity : public ZEntityImpl, public IBoolCondition
{
public:
    TArray<TEntityRef<ZBoxVolumeEntity>> m_Boxes;
    TArray<TEntityRef<ZSphereVolumeEntity>> m_Spheres;
    TArray<TEntityRef<ZSpatialEntity>> m_Spatials;
    bool m_bEnabled;
    bool m_TriggerOnHitman;
    bool m_TriggerOnActorAlive;
    bool m_TriggerOnActorDead;
    bool m_TriggerOnThrownItem;
    TArray<TEntityRef<ZVolumeTriggerEntity>> m_TriggerEntities;
    TArray<TEntityRef<ZSpatialEntity>> m_ExclusionList;
    TEntityRef<ISoundPlayable> m_SoundFootstepSweetenerHM;
    TEntityRef<ISoundPlayable> m_SoundFootstepSweetenerNPC;
    __int8 m_bActivated : 1;
    __int8 m_bColliding : 1;
    __int8 m_bRegistered : 1;
    ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull> m_BoolConditionChangedEvent;
};
