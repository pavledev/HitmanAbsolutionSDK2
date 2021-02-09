#pragma once

#include "ZEntityImpl.h"
#include "ISoundChannelGroup.h"
#include "TEntityRef.h"
#include "ISoundEffect.h"

class __declspec(align(4)) ZSoundChannelGroupBase : public ZEntityImpl, public ISoundChannelGroup
{
public:
    float m_fAttenuation;
    float m_fPitch;
    TEntityRef<ISoundEffect> m_pEffect;
    float m_fAttenuationGain;
    float m_fPitchShift;
    float m_fDuckingAttenuation;
    float m_fConfigAttenuation;
    float m_fAudibilityWeight;
    FMOD::ChannelGroup* m_pChannelGroup;
    TArray<FMOD::Channel*> m_pChannels;
    bool m_bIsSilent;
};
