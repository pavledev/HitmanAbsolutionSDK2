#pragma once

#include "ZSoundPlayerChannel.h"
#include "FMOD_CHANNEL_CALLBACKTYPE.h"

class ISoundPlayerChannelOwner
{
public:
    virtual ~ISoundPlayerChannelOwner();
    virtual void ChannelFailedCallback(ZSoundPlayerChannel*);
    virtual void ChannelPlayCallback(int, ZSoundPlayerChannel*);
    virtual void ChannelOwnerCallback(FMOD_CHANNEL_CALLBACKTYPE, void*, void*, ZSoundPlayerChannel*);
};
