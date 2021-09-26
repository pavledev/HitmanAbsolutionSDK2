#pragma once

#include "ZEntityImpl.h"
#include "ISoundChannelGroup.h"
#include "TEntityRef.h"
#include "ISoundEffect.h"

class ZSoundChannelGroupBase : public ZEntityImpl, public ISoundChannelGroup
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fAttenuation;
	float m_fPitch;
	TEntityRef<ISoundEffect> m_pEffect;
	float m_fAttenuationGain;
	float m_fPitchShift;
	float m_fDuckingAttenuation;
	float m_fConfigAttenuation;
	float m_fAudibilityWeight;
	FMOD::ChannelGroup* m_pChannelGroup;
	TArray<FMOD::Channel*> m_pChannels;
	bool m_bIsSilent;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundChannelGroupBase() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	float GetAttenuation() const override;
	void SetAttenuationGain(float fAttenuationGain) override;
	float GetPitchShift() const override;
	void SetPitchShift(float fPitchShift) override;
	FMOD::ChannelGroup* GetFMODChannelGroup() override;
	void SetConfigAttenuation(float fAttenuation) override;
	void SetAudibilityWeight(float fAudibilityWeight) override;
	void Init() override;

	void AttachEffectInstance(FMOD::DSP* pEffect, void* pOwner) override;
	bool IsSilent() const override;

	ZSoundChannelGroupBase() = default;
	static void RegisterType();
	ZSoundChannelGroupBase(ZComponentCreateInfo& info);
	void OnAttenuationChanged();
	void OnPitchChanged();
	void OnEffectChanged();
	void OnSetAttenuationGain(float fValue);
	void OnSetPitchShift(float fValue);
	void OnSetDuckingAttenuation(float fValue);
	void UpdateVolume();
	void UpdatePitch();
};
