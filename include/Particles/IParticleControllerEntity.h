#pragma once

#include "IComponentInterface.h"
#include "ZParticleEmitterBaseEntity.h"
#include "IParticleModifierEntity.h"
#include "IParticleHeirEntity.h"
#include "IParticleColliderEntity.h"

class IParticleControllerEntity : public IComponentInterface
{
public:
    virtual void RegisterEmitter(ZParticleEmitterBaseEntity*, bool);
    virtual void UnregisterEmitter(ZParticleEmitterBaseEntity*, bool);
    virtual void EnableEmitter(ZParticleEmitterBaseEntity*, bool);
    virtual bool DisableEmitter(ZParticleEmitterBaseEntity*, bool);
    virtual void RegisterModifier(const struct TEntityRef<IParticleModifierEntity>*);
    virtual void UnregisterModifier(const struct TEntityRef<IParticleModifierEntity>*);
    virtual void RegisterHeir(const struct TEntityRef<IParticleHeirEntity>*);
    virtual void UnregisterHeir(const struct TEntityRef<IParticleHeirEntity>*);
    virtual void HeirChanged();
    virtual void RegisterCollider(const TEntityRef<IParticleColliderEntity>*);
    virtual void UnregisterCollider(const TEntityRef<IParticleColliderEntity>*);
};
