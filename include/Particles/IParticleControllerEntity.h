#pragma once

#include "IComponentInterface.h"
#include "ZParticleEmitterBaseEntity.h"
#include "IParticleModifierEntity.h"
#include "IParticleHeirEntity.h"
#include "IParticleColliderEntity.h"

class __declspec(novtable) IParticleControllerEntity : public IComponentInterface
{
public:
	~IParticleControllerEntity() override = default;
	virtual void RegisterEmitter(ZParticleEmitterBaseEntity* particleEmitterBaseEntity, bool param2) = 0;
	virtual void UnregisterEmitter(ZParticleEmitterBaseEntity* particleEmitterBaseEntity, bool param2) = 0;
	virtual void EnableEmitter(ZParticleEmitterBaseEntity* particleEmitterBaseEntity, bool param2) = 0;
	virtual bool DisableEmitter(ZParticleEmitterBaseEntity* particleEmitterBaseEntity, bool param2) = 0;
	virtual void RegisterModifier(const TEntityRef<IParticleModifierEntity>& entityRef) = 0;
	virtual void UnregisterModifier(const TEntityRef<IParticleModifierEntity>& entityRef) = 0;
	virtual void RegisterHeir(const TEntityRef<IParticleHeirEntity>& entityRef) = 0;
	virtual void UnregisterHeir(const TEntityRef<IParticleHeirEntity>& entityRef) = 0;
	virtual void HeirChanged() = 0;
	virtual void RegisterCollider(const TEntityRef<IParticleColliderEntity>& entityRef) = 0;
	virtual void UnregisterCollider(const TEntityRef<IParticleColliderEntity>& entityRef) = 0;

	static void RegisterType();
	IParticleControllerEntity() = default;
};
