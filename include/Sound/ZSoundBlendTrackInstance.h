#pragma once

#include "ISoundEffectAttachable.h"
#include "ZSoundBlendEvent.h"
#include "ZSoundBlendTrack.h"

class alignas(4) ZSoundBlendTrackInstance : public ISoundEffectAttachable
{
public:
    ZSoundBlendEvent* m_pEventOwner;
    FMOD::ChannelGroup* m_pChannelGroup;
    ZSoundBlendItemManager m_ItemManager;
    TList<ZSoundBlendItemInstance> m_pPlayingItemInstances;
    TEntityRef<ZSoundBlendTrack> m_pTrack;
    TArray<FMOD::DSP*> m_aEffects;
    int m_nTrackIndex;
    bool m_bDisposable;
};
