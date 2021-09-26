#pragma once

#include "IComponentInterface.h"
#include "ZParticleEmitterBaseEntity.h"
#include "ParticleRenderJobEntry.h"
#include "ParticleRenderJobFeedback.h"

class __declspec(novtable) IParticleRenderEntity : public IComponentInterface
{
public:
	~IParticleRenderEntity() override = default;
	virtual void OnMaxNumParticlesChanged() = 0;
	virtual void AssignEmitterSpaceEntry(ZParticleEmitterBaseEntity* particleEmitterBaseEntity) = 0;
	virtual void ReleaseEmitterSpaceEntry(ZParticleEmitterBaseEntity* particleEmitterBaseEntity) = 0;
	virtual void OnBeginUpdate_Pre(ParticleRenderJobEntry* particleRenderJobEntry, unsigned int param2) = 0;
	virtual void OnEndUpdate(ParticleRenderJobFeedback* particleRenderJobFeedback) = 0;

	static void RegisterType();
	IParticleRenderEntity(const IParticleRenderEntity& __that);
	IParticleRenderEntity() = default;
	IParticleRenderEntity& operator=(const IParticleRenderEntity& __that);
};
