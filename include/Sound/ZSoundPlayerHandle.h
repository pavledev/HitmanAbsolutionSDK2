#pragma once

#include "SSoundPlayerHandleKey.h"
#include <fmod.hpp>
#include "TResourcePtr.h"
#include "ZWaveBankData.h"
#include "ESoundNonBlockingLoadStage.h"
#include "ZSoundPlayerChannel.h"
#include "SResourceHeaderHeaderEx.h"

class ZSoundPlayerHandle
{
    SSoundPlayerHandleKey m_sKey;
    ZRuntimeResourceID m_runtimeResourceID;
    ZRuntimeResourceID m_streamResourceID;
    FMOD::Sound* m_pSound;
    FMOD::Sound* m_pSubSound;
    unsigned int m_nSoundMode;
    int m_nNumChannels;
    int m_nNumSubSounds;
    int m_nInitialSubSound;
    TResourcePtr<ZWaveBankData> m_pResourcePtr;
    EWaveBankMemoryLoadRTType m_eLoadType;
    ESoundNonBlockingLoadStage m_eNonBlockingLoadingStage;
    ZSoundPlayerChannel* m_pPendingChannel;
    ZSoundPlayerChannel* m_pChannelList;
    SResourceHeaderHeaderEx m_sStreamResourceHeaderEx;
    TRefCountPtr<ZSoundPlayerCallbackExtraData> m_pStreamExtraDataRef;
    int m_StreamHandle;
    int m_nStreamFileOffset;
    int m_nStreamSoundSize;
    bool m_bStopPending;
    bool m_bPausePending;
    bool m_bUnregisterUnloadListener;
    unsigned int m_nSignature1;
    unsigned int m_nSignature2;
};
