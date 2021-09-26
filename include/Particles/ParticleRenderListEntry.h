#pragma once

#include "ZParticleRenderEntityBase.h"

struct ParticleRenderListEntry
{
	enum TYPE
	{
		SPRITE_ARRAY = 0,
		SPAWN_ENTITY = 1,
		FAIL = 2
	};

	ZParticleRenderEntityBase* m_pRenderEntity;
	ParticleRenderListEntry* m_pNext;
	ParticleRenderListEntry* m_pPrevious;
	TYPE m_Type;

	ParticleRenderListEntry() = default;
	~ParticleRenderListEntry() = default;
};
