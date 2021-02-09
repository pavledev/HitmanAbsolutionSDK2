#pragma once

#include "TEntityRef.h"
#include "ISoundMaterialDescriptor.h"

class IRenderMaterialDescriptor
{
public:
    virtual TEntityRef<ISoundMaterialDescriptor>* GetSoundMaterialDescriptor(TEntityRef<ISoundMaterialDescriptor>* result);
    virtual float GetWetnessFactor();
    virtual ~IRenderMaterialDescriptor();
};
