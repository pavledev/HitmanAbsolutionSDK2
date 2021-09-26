#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ESoundGlobalReverb.h"
#include "ESoundChannelGroup.h"
#include "TArrayIterator.h"
#include "ESoundFadeMode.h"
#include "SComponentMapEntry.h"
#include "ZEntityRef.h"
#include "ZVariantRef.h"

class ZSoundSpeakerLevelParameter;
class ZSoundMultiLayerControl;
class ZSoundSpatialParameter;
class ZSoundVolumetricAspect;
class ZSoundAmbienceElement;
class ISoundChannelGroup;
class ISoundGroup;
class ZComponentCreateInfo;
class ZSoundPlayerChannel;
namespace FMOD {
class ChannelGroup;
}  // namespace FMOD
struct STypeID;

class __declspec(novtable) ZSoundPlayableBase : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fAttenuation;
	float m_fPitch;
	float m_fDefaultFrequency;
	float m_fAttenuationRandomizer;
	float m_fPitchRandomizer;
	float m_fFadeInDuration;
	float m_fFadeOutDuration;
	float m_fMinLowpassCutoffFrequency;
	float m_fMaxLowpassCutoffFrequency;
	bool m_bPlayOnGameStart;
	bool m_bActivated;
	bool m_bRealtimeFade;
	TEntityRef<ISoundGroup> m_pSoundGroup;
	unsigned int m_nMemoryOptimizedData;
	float m_fOcclusionAttenuation;
	float m_fAttenuationGain;
	float m_fPitchShift;
	float m_fAmbienceGainMultiplier;
	float m_fAmbiencePitchShift;
	float m_fAmbienceLowpassCutoff;
	float m_fOcclusionLowpassCutoff;
	float m_fCurrentCombinedLowpassCutoff;
	ZSoundSpeakerLevelParameter* m_pSpeakerLevelParameter;
	ZSoundMultiLayerControl* m_pMultiLayerControl;
	ZSoundSpatialParameter* m_pSpatialParameter;
	ZSoundVolumetricAspect* m_pVolumetricAspect;
	ZSoundAmbienceElement* m_pAmbienceElement;
	ESoundGlobalReverb m_eSoundGlobalReverb;
	float m_fGlobalReverb1Attenuation;
	ESoundChannelGroup m_eChannelGroupMapping;
	TEntityRef<ISoundChannelGroup> m_pChannelGroup;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundPlayableBase() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	virtual void Activate() = 0;
	virtual void Deactivate() = 0;
	virtual void RegisterSpatialParameter(ZSoundSpatialParameter* pSpatial);
	virtual void SetGamePaused(bool bPaused);
	virtual void Play() = 0;
	virtual void Stop() = 0;
	virtual void Terminate();
	virtual ZEntityRef GetEntityRef() const = 0;
	virtual bool IsPlaying() const;
	virtual void Update(float deltaTime);
	virtual void OnChannelReady(ZSoundPlayerChannel* pChannel);
	virtual TArrayIterator<ZSoundPlayerChannel*> ChannelsBegin() = 0;
	virtual TArrayIterator<ZSoundPlayerChannel*> ChannelsEnd() = 0;
	virtual bool ChannelsEmpty() const = 0;
	virtual int GetNumChannels() const = 0;
	virtual int GetNumInputChannels() const = 0;
	virtual bool IsGamePaused() const;
	virtual bool IsPaused() const;
	virtual void OnPlay() = 0;
	virtual void OnStop() = 0;
	virtual void OnPause();
	virtual void SetPausedState(bool bPaused);

	ZSoundPlayableBase() = default;
	static void RegisterType();
	ZSoundPlayableBase(ZComponentCreateInfo& info);
	ZSoundSpeakerLevelParameter* GetSpeakerLevelParameter();
	ZSoundMultiLayerControl* GetMultiLayerControl();
	ZSoundSpatialParameter* GetSpatialParameter();
	ZSoundVolumetricAspect* GetVolumetricAspect();
	ZSoundAmbienceElement* GetAmbienceElement();
	TEntityRef<ISoundGroup> GetSoundGroup() const;
	bool IsSpatial() const;
	void RegisterSpeakerLevelParameter(ZSoundSpeakerLevelParameter* pSpeakerLevel);
	void RegisterMultiLayerControl(ZSoundMultiLayerControl* pMultiLayerControl);
	void RegisterVolumetricAspect(ZSoundVolumetricAspect* pVolumetric);
	void RegisterAmbienceElement(ZSoundAmbienceElement* pAmbienceElement);
	void UpdatePlayIndex(unsigned int nPlayIndex);
	bool IsPlayOnGameStart() const;
	void OnSetAttenuationGain(float fAttenuationGain);
	void OnSetPitchShift(float fPitch);
	void OnAttenuationChanged();
	void OnPitchChanged();
	void OnMinLowpassCutoffFrequencyChanged();
	void OnMaxLowpassCutoffFrequencyChanged();
	void OnChannelGroupChanged();
	void OnSoundReverbTargetChanged();
	void OnGlobalReverb1AttenuationChanged();
	void OnSoundGroupChanged();
	void SetAttenuationGain(float fAttenuationGain);
	void SetPitchShift(float fPitchShift);
	void UpdateVolume(ZSoundPlayerChannel* pChannel);
	void UpdatePitch(ZSoundPlayerChannel* pChannel);
	void UpdatePausedState(ZSoundPlayerChannel* pChannel);
	void UpdateReverbLevel(ZSoundPlayerChannel* pChannel);
	void UpdateLowpass(bool bForce, ZSoundPlayerChannel* pChannel);
	void SetAmbienceLowpassCutoff(float fCutoff);
	void SetOcclusionLowpassCutoff(float fCutoff);
	void StartedPlaying();
	void FinishedPlaying();
	void SetFadeMode(const ESoundFadeMode& eFadeMode);
	void OnActivatedChanged();
	FMOD::ChannelGroup* GetFMODChannelGroup();
	bool HasPlayIndex() const;
	void ClearPlayIndex();
};
