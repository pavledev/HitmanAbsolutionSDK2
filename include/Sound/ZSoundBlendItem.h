#pragma once

#include "ZEntityImpl.h"
#include "TResourcePtr.h"
#include "ZWaveBankData.h"
#include "ESoundPlayParameters.h"
#include "ESoundBlendLoopMode.h"
#include "ZSoundSelector.h"
#include "ZSoundBlendContainerBase.h"

class ZSoundBlendItem : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fMinParam;
	float m_fMaxParam;
	float m_fAttenuation;
	float m_fPitch;
	float m_fFadeInDuration;
	float m_fFadeOutDuration;
	float m_fRetriggerMinTime;
	float m_fRetriggerMaxTime;
	float m_fRetriggerTimeMultiplier;
	TResourcePtr<ZWaveBankData> m_WaveBankResourceID;
	ESoundPlayParameters m_ePlayParameters;
	int m_nNoRepeatCount;
	int m_nChannel;
	ESoundBlendLoopMode m_eLoopMode;
	float m_fAttenuationRandomizer;
	float m_fPitchRandomizer;
	float m_fRandomStartOffset;
	bool m_bRealtimeFade;
	bool m_bStreamedIn : 1;
	float m_fRetriggerTimeFactor;
	ZSoundSelector m_selector;
	ZSoundBlendContainerBase* m_pContainerOwner;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundBlendItem() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	void GetStreamableIncludes(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef>>& streamableIncludes) const override;
	void Init() override;

	ZSoundBlendItem() = default;
	static void RegisterType();
	ZSoundBlendItem(ZComponentCreateInfo& Info);
	int SelectChannel();
	float GenerateRandomTimeUnscaled() const;
	float GetTimeScale() const;
	void OnWaveBankResourceIDChanged(const TResourcePtr<ZWaveBankData>& pOldWaveBank);
	void OnAttenuationChanged();
	void OnPitchChanged();
	void OnPlayParametersChanged();
	void OnNoRepeatCountChanged();
};
