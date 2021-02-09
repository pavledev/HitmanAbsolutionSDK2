#pragma once

#include "ZEntityImpl.h"
#include "TResourcePtr.h"
#include "ZWaveBankData.h"
#include "ESoundPlayParameters.h"
#include "ESoundBlendLoopMode.h"
#include "ZSoundSelector.h"
#include "ZSoundBlendContainerBase.h"

class ZSoundBlendItem : public ZEntityImpl
{
public:
    float m_fMinParam;
    float m_fMaxParam;
    float m_fAttenuation;
    float m_fPitch;
    float m_fFadeInDuration;
    float m_fFadeOutDuration;
    float m_fRetriggerMinTime;
    float m_fRetriggerMaxTime;
    float m_fRetriggerTimeMultiplier;
    TResourcePtr<ZWaveBankData> m_WaveBankResourceID;
    ESoundPlayParameters m_ePlayParameters;
    int m_nNoRepeatCount;
    int m_nChannel;
    ESoundBlendLoopMode m_eLoopMode;
    float m_fAttenuationRandomizer;
    float m_fPitchRandomizer;
    float m_fRandomStartOffset;
    bool m_bRealtimeFade;
    __int8 m_bStreamedIn : 1;
    float m_fRetriggerTimeFactor;
    ZSoundSelector m_selector;
    ZSoundBlendContainerBase* m_pContainerOwner;
};
