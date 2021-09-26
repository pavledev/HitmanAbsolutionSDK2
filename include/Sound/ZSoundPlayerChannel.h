#pragma once

#include "ISoundPlayerChannel.h"
#include "ZSoundGroupTarget.h"
#include "SSoundChannelUserData.h"
#include "ESoundFadeMode.h"
#include "ESOUND_3DROLLOFF_TYPE.h"
#include "ZDelegate.h"
#include "ZGameTime.h"
#include "ZString.h"
#include "float4.h"
#include "fmod.h"

class ZSoundBlendEvent;
class ZSoundPlayerHandle;
class ZWaveBankData;
class ISoundChannelGroup;
class ISoundPlayerChannelOwner;
class IWaveBankData;
class ZSoundPlayerCallbackExtraData;
namespace FMOD {
class Channel;
class ChannelGroup;
class DSP;
class DSPConnection;
class Sound;
}  // namespace FMOD
template <class T> class TEntityRef;
template <class T> class TRefCountPtr;

class ZSoundPlayerChannel : public ISoundPlayerChannel, public ZSoundGroupTarget
{
public:
	struct STempData
	{
		float4 m_vPos;
		float m_fVolume;
		float m_fPitchMultiplier;
		float m_fStartOffset;
		bool m_bIs3D;
		int m_nLoopCount;
		int m_nChannelMode;
	};

	SSoundChannelUserData m_ChannelUserData;
	void* m_pUserData;
	FMOD::Channel* m_pFMODChannel;
	ISoundPlayerChannelOwner* m_pOwner;
	ZSoundPlayerHandle* m_pHandle;
	float m_fDefaultFrequency;
	int m_nClippedChannel;
	ZSoundPlayerChannel* m_pPrevChannel;
	ZSoundPlayerChannel* m_pNextChannel;
	ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> m_FailedCallback;
	ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)> m_StartedCallback;
	ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> m_StoppedCallback;
	ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> m_SeqFailedCallback;
	ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)> m_SeqStartedCallback;
	ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> m_SeqStoppedCallback;
	void* m_pCallbackUserData;
	void* m_pSeqCallbackUserData;
	bool m_bGloballyPaused;
	bool m_bChannelPaused;
	unsigned char m_eInitializationStage;
	unsigned int m_nChannelFlags;
	const unsigned int m_nUniqueID;
	int m_nRandSeed;
	ESoundFadeMode m_eFadeMode;
	float m_fFadeVolume;
	float m_fFadeVolumeDelta;
	float m_fChannelVolume;
	float m_fRandomVolume;
	float m_fBlendVolume;
	float m_fSourceVolume;
	float m_fChannelPitch;
	float m_fBlendPitch;
	float m_fRandomPitch;
	int m_nPriority;
	FMOD::DSP* m_pLowpassDSP;
	float m_fLowpassCutoffFrequency;
	float m_fFocusLowpassCutoffFrequency;
	ZGameTime m_timestamp;
	ZSoundBlendEvent* m_pBlendEvent;
	STempData* m_pTempData;
	unsigned int m_nSignature1;
	unsigned int m_nSignature2;

	~ZSoundPlayerChannel() override = default;
	float GetPlayPosition() override;
	void SetGloballyPaused(bool paused) override;
	void SetChannelPaused(bool paused) override;
	void Stop() override;
	IWaveBankData* GetWavebankData() override;
	int GetSubSound() override;
	void* GetCallbackUserData() override;
	void* GetUserData() override;
	void SetOwner(ISoundPlayerChannelOwner* pOwner) override;
	void SetFailedCallback(ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> FailedCallback) override;
	void SetStartedCallback(ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)> StartedCallback) override;
	void SetStoppedCallback(ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> StoppedCallback) override;
	const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& GetFailedCallback() const override;
	const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)>& GetStartedCallback() const override;
	const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& GetStoppedCallback() const override;
	void SetChannelFlags(unsigned int nChannelFlags) override;
	unsigned int GetChannelFlags() override;
	unsigned int GetUniqueID() const override;
	float GetAudibility(bool bIncludeSoundGroupFadeLevel) override;
	float GetRawAudibility(const float4& vListenerPos) override;
	void SetAttenuation(float fAttenuation) override;
	void SetPitch(float fPitch) override;
	void SetPitchFromMultiplier(float fPitchMultiplier) override;
	void SetPlayPosition(float fPosition) override;
	float GetLength() override;
	void SetCallbackUserData(void* pCallBackUserData) override;
	void SetUserData(void* pUserData) override;
	void SetChannelGroup(TEntityRef<ISoundChannelGroup> pChannelGroup) override;
	void SetDelay(float fDelayTime) override;
	void SetMode2D() override;
	void SetLowpassCutoffFrequency(float fCutoffFrequency) override;
	void SetSeqCallbackUserData(void* pSeqCallBackUserData) override;
	void* GetSeqCallbackUserData() override;
	void ClearSequenceCallbacks() override;
	virtual ZWaveBankData* GetWavebankDataInternal();
	virtual void SetFadeMode(ESoundFadeMode eFadeMode, float fFadeTime);
	virtual void SetVolume(float volume);
	virtual void SetBlendVolume(float fBlendVolume);
	virtual void SetSourceVolume(float fSourceVolume);
	virtual void SetBlendPitch(float fBlendPitch);
	virtual void SetFocusLowpassCutoff(float fCutoffFrequency);

	int GetPriority() override;
	float GetSquaredDistanceToListener(const float4& vListenerPos) override;
	ZGameTime GetTimestamp() override;
	void StopTarget() override;
	ZString GetSoundGroupTargetName() const override;
	bool UpdateSoundGroupFade(bool bMuted, float fFadeTime, float fDeltaTime) override;

	ZSoundPlayerChannel() = default;
	ZSoundPlayerChannel(ZSoundPlayerHandle* pHandle, ISoundPlayerChannelOwner* pOwner, void* pUserData, float fRandomVolume, float fRandomPitch, int nPriority, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> FailedCallback, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)> StartedCallback, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> StoppedCallback, void* pCallbackUserData, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> SeqFailedCallback, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)> SeqStartedCallback, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> SeqStoppedCallback, void* pSeqCallbackUserData);
	void Set3DCustomRolloff(const FMOD_VECTOR* points, int numpoints);
	void Set3DRolloffType(ESOUND_3DROLLOFF_TYPE type);
	FMOD::ChannelGroup* GetChannelGroup();
	void SetLFEVolume(float fVolume);
	int GetNumInputChannels() const;
	bool UpdateFade(float fDeltaTime);
	FMOD_RESULT set3DAttributes(const FMOD_VECTOR* pos, const FMOD_VECTOR* vel);
	FMOD_RESULT set3DPanLevel(float level);
	FMOD_RESULT set3DMinMaxDistance(float mindistance, float maxdistance);
	FMOD_RESULT set3DConeSettings(float insideconeangle, float outsideconeangle, float outsidevolume);
	FMOD_RESULT set3DConeOrientation(FMOD_VECTOR* orientation);
	FMOD_RESULT set3DDopplerLevel(float level);
	FMOD_RESULT setMode(unsigned int mode);
	FMOD_RESULT getMode(unsigned int* mode);
	FMOD_RESULT setLoopCount(int loopcount);
	FMOD_RESULT setChannelGroup(FMOD::ChannelGroup* channelgroup);
	FMOD_RESULT setVolume(float volume);
	FMOD_RESULT setFrequency(float frequency);
	FMOD_RESULT getAudibility(float* audibility);
	FMOD_RESULT getVolume(float* volume);
	FMOD_RESULT setSpeakerLevels(FMOD_SPEAKER speaker, float* levels, int numlevels);
	FMOD_RESULT setSpeakerMix(float frontleft, float frontright, float center, float lfe, float backleft, float backright, float sideleft, float sideright);
	FMOD_RESULT setReverbProperties(const FMOD_REVERB_CHANNELPROPERTIES* prop);
	FMOD_RESULT getReverbProperties(FMOD_REVERB_CHANNELPROPERTIES* prop);
	FMOD_RESULT setCallback(FMOD_RESULT (*callback)(FMOD_CHANNEL* fmodChannel, FMOD_CHANNEL_CALLBACKTYPE fmodChannelCallbacktype, void* param3, void* param4));
	FMOD_RESULT setPriority(int priority);
	FMOD_RESULT setMute(bool mute);
	FMOD_RESULT setPosition(unsigned int position, unsigned int postype);
	FMOD_RESULT getPosition(unsigned int* position, unsigned int postype);
	FMOD_RESULT setDelay(FMOD_DELAYTYPE delaytype, unsigned int delayhi, unsigned int delaylo);
	FMOD_RESULT getCurrentSound(FMOD::Sound** sound);
	FMOD_RESULT isPlaying(bool* isplaying);
	FMOD_RESULT isVirtual(bool* isvirtual);
	FMOD_RESULT getDSPHead(FMOD::DSP** dsp);
	FMOD_RESULT addDSP(FMOD::DSP* dsp, FMOD::DSPConnection** connection);
	float GetDefaultFrequency() const;
	FMOD::Channel* GetFMODChannel();
	void SetRandSeed(int nSeed);
	int GetRandSeed();
	void SetBlendEvent(ZSoundBlendEvent* pBlendEvent);
	ZSoundBlendEvent* GetBlendEvent() const;
	SSoundChannelUserData* GetChannelUserData();
	void UpdateVolume();
	void UpdatePitch();
	void UpdateCutoff();
};
