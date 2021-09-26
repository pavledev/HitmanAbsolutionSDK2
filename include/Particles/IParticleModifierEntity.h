#pragma once

#include "IComponentInterface.h"

class __declspec(novtable) IParticleModifierEntity : public IComponentInterface
{
public:
	~IParticleModifierEntity() override = default;
	virtual unsigned int ConstSize() = 0;
	virtual ParticleConstInfo ConstPack(void* param1) = 0;
	virtual TEntityRef<IParticleModifierEntity> GetNextModifier() = 0;
	virtual void SetChainParticleController(ZParticleControllerEntity* particleControllerEntity) = 0;

	static void RegisterType();
	IParticleModifierEntity() = default;
};
