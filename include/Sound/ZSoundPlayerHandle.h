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
public:
	struct SSoundPlayerHandleKey
	{
		ZRuntimeResourceID m_pResourceID;
		unsigned int m_nSoundMode;

		bool operator<(const SSoundPlayerHandleKey& rhs) const;
		SSoundPlayerHandleKey() = default;
	};

	struct SResourceHeaderHeaderEx : SResourceHeaderHeader
	{
		unsigned int m_nExtraDataSize;
	};

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

	ZSoundPlayerHandle() = default;
	ZSoundPlayerHandle(TResourcePtr<ZWaveBankData> pResource, unsigned int nSoundMode, int nInitialSubSound, bool* pValid);
	~ZSoundPlayerHandle() = default;
	ESoundPlayerPendingResult UpdatePending();
	ZSoundPlayerChannel* PlaySound(const int nSubSound, const float4& vPos, const float fVolume, const float fPitchMultiplier, const float fRandomVolume, const float fRandomPitch, const float fStartOffset, const bool bIs3D, const bool bChannelPaused, const unsigned int nChannelFlags, const int nLoopCount, const unsigned int nChannelMode, const int nPriority, ISoundPlayerChannelOwner* pOwner, void* pUserData, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> FailedCallback, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)> StartedCallback, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> StoppedCallback, void* pCallbackUserData, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> SeqFailedCallback, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)> SeqStartedCallback, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> SeqStoppedCallback, void* pSeqCallbackUserData);
	ZRuntimeResourceID GetRuntimeResourceID();
	const SSoundPlayerHandleKey& GetKey() const;
	const int GetStreamHandle() const;
	const int GetStreamFileOffset() const;
	const int GetStreamSize() const;
	EWaveBankMemoryLoadRTType GetLoadType() const;
	ZWaveBankData* GetRawPointer() const;
	void SetPausePending(bool bPaused);
	void StreamReadyCallback(const ZRuntimeResourceID id, ZResourceStub* pStub, int nPriority, const ZString sFileName, unsigned int nFileOffset);
	void StreamHeaderCallback(int handle, void* buffer, unsigned int nPosition, unsigned int nSize);
	void StreamExtraDataCallback(int handle, void* buffer, unsigned int nPosition, unsigned int nSize);
	static FMOD_RESULT __stdcall FMODChannelCallback(FMOD_CHANNEL* pChannel, FMOD_CHANNEL_CALLBACKTYPE type, void* commanddata1, void* commanddata2);
	void OnResourceUnloaded(const ZRuntimeResourceID& id);
	void StopAllChannels();
};
