#pragma once

#include "ZString.h"
#include "TEntityRef.h"
#include "ZSoundBlendContainerPhysics.h"

class ISoundMaterialDescriptor
{
public:
    virtual ~ISoundMaterialDescriptor();
    virtual int GetSoundMaterialType();
    virtual ZString* GetSoundMaterialName(ZString* result);
    virtual TEntityRef<ZSoundBlendContainerPhysics>* GetPhysicsBlendContainer(TEntityRef<ZSoundBlendContainerPhysics>* result, ESoundCollisionType);
};
