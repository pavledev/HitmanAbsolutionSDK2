#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ISoundGroup.h"
#include "ESoundGlobalReverb.h"
#include "ESoundChannelGroup.h"
#include "ISoundChannelGroup.h"
#include "TArrayIterator.h"
#include "ZSoundPlayerChannel.h"

class ZSoundSpeakerLevelParameter;
class ZSoundMultiLayerControl;
class ZSoundSpatialParameter;
class ZSoundVolumetricAspect;
class ZSoundAmbienceElement;

class ZSoundPlayableBase : public ZEntityImpl
{
public:
    float m_fAttenuation;
    float m_fPitch;
    float m_fDefaultFrequency;
    float m_fAttenuationRandomizer;
    float m_fPitchRandomizer;
    float m_fFadeInDuration;
    float m_fFadeOutDuration;
    float m_fMinLowpassCutoffFrequency;
    float m_fMaxLowpassCutoffFrequency;
    bool m_bPlayOnGameStart;
    bool m_bActivated;
    bool m_bRealtimeFade;
    TEntityRef<ISoundGroup> m_pSoundGroup;
    unsigned int m_nMemoryOptimizedData;
    float m_fOcclusionAttenuation;
    float m_fAttenuationGain;
    float m_fPitchShift;
    float m_fAmbienceGainMultiplier;
    float m_fAmbiencePitchShift;
    float m_fAmbienceLowpassCutoff;
    float m_fOcclusionLowpassCutoff;
    float m_fCurrentCombinedLowpassCutoff;
    ZSoundSpeakerLevelParameter* m_pSpeakerLevelParameter;
    ZSoundMultiLayerControl* m_pMultiLayerControl;
    ZSoundSpatialParameter* m_pSpatialParameter;
    ZSoundVolumetricAspect* m_pVolumetricAspect;
    ZSoundAmbienceElement* m_pAmbienceElement;
    ESoundGlobalReverb m_eSoundGlobalReverb;
    float m_fGlobalReverb1Attenuation;
    ESoundChannelGroup m_eChannelGroupMapping;
    TEntityRef<ISoundChannelGroup> m_pChannelGroup;

    virtual void Activate();
    virtual void Deactivate();
    virtual void RegisterSpatialParameter(ZSoundSpatialParameter*);
    virtual void SetGamePaused(bool);
    virtual void Play();
    virtual void Stop();
    virtual void Terminate();
    virtual ZEntityRef* GetEntityRef(ZEntityRef* result);
    virtual bool IsPlaying();
    virtual void Update(float);
    virtual void OnChannelReady(ZSoundPlayerChannel*);
    virtual TArrayIterator<ZSoundPlayerChannel*> ChannelsBegin();
    virtual TArrayIterator<ZSoundPlayerChannel*> ChannelsEnd();
    virtual bool ChannelsEmpty();
    virtual int GetNumChannels();
    virtual int GetNumInputChannels();
    virtual bool IsGamePaused();
    virtual bool IsPaused();
    virtual void OnPlay();
    virtual void OnStop();
    virtual void OnPause();
    virtual void SetPausedState(bool);
};
