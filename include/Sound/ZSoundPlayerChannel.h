#pragma once

#include "ISoundPlayerChannel.h"
#include "ZSoundGroupTarget.h"
#include "SSoundChannelUserData.h"
#include "ESoundFadeMode.h"
#include "STempData.h"

class ZSoundBlendEvent;
class ZSoundPlayerHandle;

class ZSoundPlayerChannel : public ISoundPlayerChannel, public ZSoundGroupTarget
{
public:
    SSoundChannelUserData m_ChannelUserData;
    void* m_pUserData;
    FMOD::Channel* m_pFMODChannel;
    ISoundPlayerChannelOwner* m_pOwner;
    ZSoundPlayerHandle* m_pHandle;
    float m_fDefaultFrequency;
    int m_nClippedChannel;
    ZSoundPlayerChannel* m_pPrevChannel;
    ZSoundPlayerChannel* m_pNextChannel;
    ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> m_FailedCallback;
    ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)> m_StartedCallback;
    ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> m_StoppedCallback;
    ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> m_SeqFailedCallback;
    ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)> m_SeqStartedCallback;
    ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> m_SeqStoppedCallback;
    void* m_pCallbackUserData;
    void* m_pSeqCallbackUserData;
    bool m_bGloballyPaused;
    bool m_bChannelPaused;
    char m_eInitializationStage;
    unsigned int m_nChannelFlags;
    const unsigned int m_nUniqueID;
    int m_nRandSeed;
    ESoundFadeMode m_eFadeMode;
    float m_fFadeVolume;
    float m_fFadeVolumeDelta;
    float m_fChannelVolume;
    float m_fRandomVolume;
    float m_fBlendVolume;
    float m_fSourceVolume;
    float m_fChannelPitch;
    float m_fBlendPitch;
    float m_fRandomPitch;
    int m_nPriority;
    FMOD::DSP* m_pLowpassDSP;
    float m_fLowpassCutoffFrequency;
    float m_fFocusLowpassCutoffFrequency;
    ZGameTime m_timestamp;
    ZSoundBlendEvent* m_pBlendEvent;
    STempData* m_pTempData;
    unsigned int m_nSignature1;
    unsigned int m_nSignature2;
};
