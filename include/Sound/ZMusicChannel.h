#pragma once

#include "ZString.h"
#include "ZRuntimeResourceID.h"
#include "FMOD.h"
#include "ZDSPHandle.h"
#include "SSoundChannelUserData.h"
#include "ZSharedPointerTarget.h"
#include "ZMusicController.h"
#include "ZMusicSoundHandle.h"
#include "ZNonCopyable.h"
#include "TSharedPointer.h"

class ZMusicChannel : public ZSharedPointerTarget, public ZNonCopyable
{
public:
	SSoundChannelUserData m_ChannelUserData;
	ZRuntimeResourceID m_id;
	int m_nSubSoundIndex;
	const ZString& m_sTrackID;
	FMOD::Channel* m_pChannel;
	TSharedPointer<ZDSPHandle> m_pDSP;
	bool m_bDSPEnabled;

	~ZMusicChannel() override = default;

	ZMusicChannel() = default;
	static TSharedPointer<ZMusicChannel> Create(const ZString& sTrackID, TSharedPointer<ZMusicSoundHandle>& pSound, ZMusicController& controller);
	void SetVolume(float fVolume);
	void SetLowpassCutoff(float fCutoffFrequency);
	const ZString& GetTrackID() const;
	void SetPaused(bool bPaused);
	void Stop();
	void SetStartDelay(unsigned long long nDelay);
	void SetEndDelay(unsigned long long nDelay);
	void SetChannelGroup(FMOD::ChannelGroup* pChannelGroup);
	void SetPosition(unsigned int nPosition);
	void OnChannelEnded();
	ZMusicChannel(const ZString& sTrackID, TSharedPointer<ZMusicSoundHandle>& pSound, ZMusicController& controller);
};
