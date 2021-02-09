#pragma once

#include "IComponentInterface.h"
#include "ZParticleEmitterBaseEntity.h"
#include "ParticleRenderJobEntry.h"
#include "ParticleRenderJobFeedback.h"

class IParticleRenderEntity : public IComponentInterface
{
public:
    virtual void OnMaxNumParticlesChanged();
    virtual void AssignEmitterSpaceEntry(ZParticleEmitterBaseEntity*);
    virtual void ReleaseEmitterSpaceEntry(ZParticleEmitterBaseEntity*);
    virtual void OnBeginUpdate_Pre(ParticleRenderJobEntry*, unsigned int);
    virtual void OnEndUpdate(ParticleRenderJobFeedback*);
};
