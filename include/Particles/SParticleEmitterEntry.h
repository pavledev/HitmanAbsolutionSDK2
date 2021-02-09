#pragma once

#include "ZParticleEmitterBaseEntity.h"

class SParticleEmitterEntry
{
public:
    ZParticleEmitterBaseEntity* ptr;
    bool bEnabled;
    SParticleBlockHeader* pBlockList;
    unsigned int nContsSize;
};
