#pragma once

#include "ZParticleEmitterBaseEntity.h"

struct SParticleEmitterEntry
{
	ZParticleEmitterBaseEntity* ptr;
	bool bEnabled;
	SParticleBlockHeader* pBlockList;
	unsigned int nContsSize;

	SParticleEmitterEntry(ZParticleEmitterBaseEntity* emitter, bool enabled, SParticleBlockHeader* blockList);
	SParticleEmitterEntry() = default;
	~SParticleEmitterEntry() = default;
};
