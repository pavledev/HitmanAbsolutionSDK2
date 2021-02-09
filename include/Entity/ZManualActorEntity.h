#pragma once

#include "ZSpatialEntity.h"
#include "ZAnimationClipEntity.h"
#include "ZCrowdEntity.h"

class alignas(4) ZManualActorEntity : public ZSpatialEntity
{
public:
    int m_nActorTemplateIndex;
    int m_nActorVariantIndex;
    bool m_bStartIdle;
    bool m_bNeverFlee;
    alignas(4) TArray<TEntityRef<ZAnimationClipEntity>> m_idleOverrideClips;
    bool m_bAllowRandomStateChanges;
    alignas(4) ZResourcePtr m_pGizmo;
    TEntityRef<ZCrowdEntity> m_pCrowd;
    unsigned int m_nActorIndex;
};
