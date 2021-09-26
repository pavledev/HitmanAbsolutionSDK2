#pragma once

#include "IComponentInterface.h"

class __declspec(novtable) IParticleColliderEntity : public IComponentInterface
{
public:
	~IParticleColliderEntity() override = default;
	virtual void ProcessParticleCollisions(const SCollidingParticle* collidingParticle, unsigned int param2) = 0;
	virtual bool IsValid() const = 0;

	static void RegisterType();
	IParticleColliderEntity() = default;
};
