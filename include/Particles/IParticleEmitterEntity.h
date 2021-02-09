#pragma once

#include "IComponentInterface.h"
#include "float4.h"
#include "ParticleConstInfo.h"

class ZParticleControllerEntity;

class IParticleEmitterEntity : public IComponentInterface
{
public:
    virtual unsigned int GetEmissionCount(float, const float4*, float4*);
    virtual bool UseEmitterSpaceParticles();
    virtual int GetEmitterSpaceEntry();
    virtual void SetEmitterSpaceEntry(int);
    virtual unsigned int ConstSize();
    virtual ParticleConstInfo* ConstPack(ParticleConstInfo* result, void*, const float4*);
    virtual void ActivateEmitter();
    virtual void DeactivateEmitter();
    virtual void ParticleControlerDeleted(const ZParticleControllerEntity*);
};
