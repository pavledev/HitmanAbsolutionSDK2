#pragma once

#include "IComponentInterface.h"

class __declspec(novtable) IParticleHeirEntity : public IComponentInterface
{
public:
	~IParticleHeirEntity() override = default;
	virtual void ParticlesHeritage(const SDeadParticle* deadParticle, unsigned int param2) = 0;
	virtual unsigned int GetNumDeadParticlesSupported() const = 0;

	static void RegisterType();
	IParticleHeirEntity() = default;
};
