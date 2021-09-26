#pragma once

#include "FMOD_CHANNEL_CALLBACKTYPE.h"
#include "SSoundChannelUserData.h"
#include "fmod.hpp"
#include "ZEntityImpl.h"

class ZSoundPersistentPlayerChannel
{
public:
	SSoundChannelUserData m_ChannelUserData;
	FMOD::Sound* m_pSound;

	ZSoundPersistentPlayerChannel() = default;
	~ZSoundPersistentPlayerChannel() = default;
	FMOD::Channel* Play(ZEntityImpl* pEntityPtr, const void* pData, unsigned int nDataSize, int nSubsoundIndex, float fAttenuation, FMOD::ChannelGroup* pChannelGroup);
	static FMOD_RESULT __stdcall FMODChannelCallback(FMOD_CHANNEL* pChannel, FMOD_CHANNEL_CALLBACKTYPE type, void* commanddata1, void* commanddata2);
};
