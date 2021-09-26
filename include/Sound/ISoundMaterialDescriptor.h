#pragma once

#include "ZString.h"
#include "TEntityRef.h"
#include "ESoundCollisionType.h"

class ZSoundBlendContainerPhysics;

class __declspec(novtable) ISoundMaterialDescriptor
{
public:
	virtual ~ISoundMaterialDescriptor() = default;
	virtual int GetSoundMaterialType() const = 0;
	virtual ZString GetSoundMaterialName() const = 0;
	virtual TEntityRef<ZSoundBlendContainerPhysics> GetPhysicsBlendContainer(ESoundCollisionType soundCollisionType) const = 0;

	ISoundMaterialDescriptor() = default;
};
