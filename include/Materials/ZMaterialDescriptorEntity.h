#pragma once

#include "IRenderMaterialDescriptor.h"
#include "TResourcePtr.h"

class ZMaterialDescriptorEntity : public IRenderMaterialDescriptor, public ZEntityImpl
{
public:
    float m_fWetnessFactor;
    TResourcePtr<ZEntityRef> m_pSoundMaterialDescriptor;
    TEntityRef<ISoundMaterialDescriptor> m_pSoundMaterialDescriptorEntity;
};
