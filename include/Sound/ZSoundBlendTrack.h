#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZSoundBlendItemSubtrack.h"
#include "ZSoundBlendEffectSubtrack.h"
#include "ISoundBlendContainer.h"

class ZSoundBlendTrackInstance;

class ZSoundBlendTrack : ZEntityImpl
{
public:
    unsigned int m_nPrimarySourceID;
    TEntityRef<ZSoundBlendItemSubtrack> m_ItemSubtrack;
    TArray<TEntityRef<ZSoundBlendEffectSubtrack>> m_EffectSubtracks;
    ISoundBlendContainer* m_pOwner;
    int m_nPrimarySourceIndex;
    bool m_bIsMuted;
    alignas(4) TArray<ZSoundBlendTrackInstance*> m_TrackInstances;
};
