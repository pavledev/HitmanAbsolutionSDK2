#pragma once

#include "ZParticleRenderEntityBase.h"

class ParticleRenderListEntry
{
public:
    ZParticleRenderEntityBase* m_pRenderEntity;
    ParticleRenderListEntry* m_pNext;
    ParticleRenderListEntry* m_pPrevious;

    enum TYPE : __int32
    {
        SPRITE_ARRAY = 0x0,
        SPAWN_ENTITY = 0x1,
        FAIL = 0x2,
    } m_Type;
};
