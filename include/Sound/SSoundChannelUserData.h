#pragma once

#include "ESoundChannelType.h"

class ZSoundPlayerChannel;
class ZSoundPersistentPlayerChannel;
class ZMusicChannel;
class ZEntityImpl;

struct SSoundChannelUserData
{
	ESoundChannelType m_eType;
	void* m_pInstancePtr;
	ZEntityImpl* m_pOwnerEntityPtr;

	SSoundChannelUserData() = default;
	~SSoundChannelUserData() = default;
	ESoundChannelType GetSoundChannelType() const;
	ZSoundPlayerChannel* GetPlayerChannel();
	ZSoundPersistentPlayerChannel* GetPersistentChannel();
	ZMusicChannel* GetMusicChannel();
	ZSoundPlayerChannel* TryGetPlayerChannel();
};
