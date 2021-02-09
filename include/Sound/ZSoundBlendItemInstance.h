#pragma once

#include "ISoundPlayerChannelOwner.h"
#include "ZSoundBlendTrackInstance.h"

class alignas(4) ZSoundBlendItemInstance : public ISoundPlayerChannelOwner
{
public:
    TEntityRef<ZSoundBlendItem> m_pSoundItem;
    ZSoundPlayerChannel* m_pChannel;
    int m_nItemIndex;
    ZSoundBlendItemManager* m_pItemManager;
    ZSoundBlendTrackInstance* m_pTrackInstance;
    ZSoundBlendEvent* m_pEventOwner;
    ZSoundSelector m_selector;
    float m_fRetriggerTimeUnscaled;
    float m_fRetriggerTimeCounter;
    bool m_bIsRetriggerable;
    float m_fCrossFadeCoeff;
    ESoundFadeMode m_eFadeMode;
    float m_fFadeVolumeMultiplier;
    float m_fFadeVelocity;
    int m_nPlayingChannels;
    bool m_bDisposable;
    bool m_bProperlyInitialized;
};
