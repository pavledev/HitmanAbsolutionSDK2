#pragma once

#include "ZBoxVolumeEntity.h"
#include "ZAnimationClipEntity.h"
#include "ZCrowdActorGroupFocalPointEntity.h"
#include "ZCrowdActorEntity.h"

class ZCrowdActorGroupEntity : public ZBoxVolumeEntity
{
public:
    unsigned int m_nGroupSize;
    TArray<TEntityRef<ZAnimationClipEntity>> m_idleOverrideClips;
    TArray<TEntityRef<ZCrowdActorGroupFocalPointEntity>> m_aFocalPoints;
    TArray<TEntityRef<ZCrowdActorEntity>> m_aExcludedActorTemplates;
    float m_nPlacementRadius;
};
