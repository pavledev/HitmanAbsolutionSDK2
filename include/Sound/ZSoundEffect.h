#pragma once

#include "ZEntityImpl.h"
#include "ISoundEffect.h"
#include "SEffectInstance.h"

class ZSoundEffect : public ZEntityImpl, public ISoundEffect
{
public:
    TArray<SEffectInstance> m_pEffectInstances;
    int m_lType;
    bool m_bActive;
    float m_fMuteTime;

    virtual void UpdateAll(FMOD::DSP*);
    virtual FMOD::DSP* CreateCustomDSP();
};
