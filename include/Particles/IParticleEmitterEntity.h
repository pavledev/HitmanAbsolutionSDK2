#pragma once

#include "IComponentInterface.h"
#include "ParticleConstInfo.h"

class ZParticleControllerEntity;
struct float4;

class __declspec(novtable) IParticleEmitterEntity : public IComponentInterface
{
public:
	~IParticleEmitterEntity() override = default;
	virtual unsigned int GetEmissionCount(float param1, const float4& param2, float4* param3) = 0;
	virtual bool UseEmitterSpaceParticles() const = 0;
	virtual int GetEmitterSpaceEntry() const = 0;
	virtual void SetEmitterSpaceEntry(int param1) = 0;
	virtual unsigned int ConstSize() = 0;
	virtual ParticleConstInfo ConstPack(void* param1, const float4& param2) = 0;
	virtual void ActivateEmitter() = 0;
	virtual void DeactivateEmitter() = 0;
	virtual void ParticleControlerDeleted(const ZParticleControllerEntity* particleControllerEntity) = 0;

	static void RegisterType();
	IParticleEmitterEntity(const IParticleEmitterEntity& __that);
	IParticleEmitterEntity() = default;
	IParticleEmitterEntity& operator=(const IParticleEmitterEntity& __that);
};
