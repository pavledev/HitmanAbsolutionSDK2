#pragma once

#include <fmod.hpp>

class ISoundEffectAttachable
{
public:
    virtual ~ISoundEffectAttachable();
    virtual void AttachEffectInstance(FMOD::DSP*, void*);
    virtual bool IsSilent();
};
