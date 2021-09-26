#pragma once

#include "ZSoundPlayerChannel.h"
#include "FMOD_CHANNEL_CALLBACKTYPE.h"

class __declspec(novtable) ISoundPlayerChannelOwner
{
public:
	virtual ~ISoundPlayerChannelOwner() = default;
	virtual void ChannelFailedCallback(ZSoundPlayerChannel* soundPlayerChannel) = 0;
	virtual void ChannelPlayCallback(int param1, ZSoundPlayerChannel* soundPlayerChannel) = 0;
	virtual void ChannelOwnerCallback(FMOD_CHANNEL_CALLBACKTYPE fmodChannelCallbacktype, void* param2, void* param3, ZSoundPlayerChannel* soundPlayerChannel) = 0;

	ISoundPlayerChannelOwner(const ISoundPlayerChannelOwner& __that);
	ISoundPlayerChannelOwner() = default;
};
