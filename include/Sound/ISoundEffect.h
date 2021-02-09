#pragma once

#include "IComponentInterface.h"
#include "ISoundEffectAttachable.h"
#include "ZGameTime.h"

class ISoundEffect : public IComponentInterface
{
public:
    virtual FMOD::DSP* CreateEffectInstance(ISoundEffectAttachable*, void*);
    virtual void DestroyEffectInstance(void*);
    virtual void UpdateAll();
    virtual void SetActive(const bool);
    virtual void Update(ZGameTime, bool);
};