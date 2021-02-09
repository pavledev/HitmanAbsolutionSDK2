#pragma once

#include "TEntityRef.h"
#include "ZSpatialEntity.h"

class alignas(4) SESEntry
{
public:
    TEntityRef<ZSpatialEntity> parentEntity;
    struct ZParticleContainerEntity* m_pParticleContainer;
    bool bInUse;
};
