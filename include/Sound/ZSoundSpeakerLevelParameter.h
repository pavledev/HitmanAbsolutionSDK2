#pragma once

#include "ZEntityImpl.h"
#include "TSharedValue.h"
#include "ZSpeakerLevels.h"
#include "TEntityRef.h"
#include "ZSoundPlayableBase.h"

class ZSoundSpeakerLevelParameter : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bMatrixModified;
	TSharedValue<ZSpeakerLevels> m_SpeakerLevels;
	float m_fReverbLevel;
	bool m_bEnablePan;
	float m_fPanAngle;
	float m_fPanAngleRandomizer;
	float m_fPanSpread;
	float m_fPanSpreadRandomizer;
	float m_fPanLFELevel;
	float m_fApproximateLFEVolumeFor3D;
	TEntityRef<ZSoundPlayableBase> m_parentEntity;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundSpeakerLevelParameter() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZSoundSpeakerLevelParameter() = default;
	static void RegisterType();
	ZSoundSpeakerLevelParameter(ZComponentCreateInfo& info);
	void UpdateSpeakerLevels(ZSoundPlayerChannel* pChannel);
	void UpdateSpeakerLevels();
	float GetApproximateLFEVolumeFor3D();
	void OnSpeakerLevelsChanged();
	void OnReverbLevelChanged();
	void OnSetReverbLevel(float fReverbLevel);
	void OnSetEnablePan(bool bEnablePan);
	void OnSetPanAngle(float fPanAngle);
	void OnSetPanAngleRandomizer(float fPanAngleRandomizer);
	void OnSetPanSpread(float fPanSpread);
	void OnSetPanSpreadRandomizer(float fPanSpreadRandomizer);
	TArrayIterator<ZSoundPlayerChannel*> ChannelsBegin();
	TArrayIterator<ZSoundPlayerChannel*> ChannelsEnd();
	bool ChannelsEmpty() const;
};
