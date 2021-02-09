#pragma once

#include "ISoundEffectAttachable.h"
#include "ZGameTime.h"

class SEffectInstance
{
public:
    FMOD::DSP* m_pDSP;
    ISoundEffectAttachable* m_pEffectAttachable;
    void* m_pOwner;
    bool m_bIsSilent;
    ZGameTime m_LastChannelEndTime;
};
