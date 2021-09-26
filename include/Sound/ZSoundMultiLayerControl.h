#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZSoundPlayableBase.h"
#include "ZSoundMultiLayerMixer.h"

class ZSoundMultiLayerControl : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<ZSoundPlayableBase> m_parentEntity;
	int m_nLFEChannel;
	TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel0;
	TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel1;
	TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel2;
	TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel3;
	TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel4;
	TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel5;
	TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel6;
	TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel7;
	float m_fReverbLevel;
	bool m_bAlignListener;
	float m_fChannelVolume[8];
	float4 m_vSpeakerDir[8];
	float4 m_vSpeakerPos[8];
	float4 m_vSpeakerDirTransformed[8];
	float4 m_vSpeakerPosTransformed[8];
	float4 m_vLastListenerPos;
	float4 m_vLastOcclusionPos;
	bool m_bIsLFE[8];
	bool m_bIsUpdated;
	unsigned long long m_nFrameUpdateTag;
	SMatrix m_mListenerMatrix;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundMultiLayerControl() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZSoundMultiLayerControl() = default;
	static void RegisterType();
	ZSoundMultiLayerControl(ZComponentCreateInfo& info);
	void MarkForUpdate();
	void PerformUpdate(ZSoundPlayerChannel* pChannel, bool bForce);
	void FrameUpdate(const SGameUpdateEvent& updateEvent);
	void OnSetChannelAttenuation0(float fValue);
	void OnSetChannelAttenuation1(float fValue);
	void OnSetChannelAttenuation2(float fValue);
	void OnSetChannelAttenuation3(float fValue);
	void OnSetChannelAttenuation4(float fValue);
	void OnSetChannelAttenuation5(float fValue);
	void OnSetChannelAttenuation6(float fValue);
	void OnSetChannelAttenuation7(float fValue);
	void OnReverbLevelChanged();
	void OnSetReverbLevel(float fReverbLevel);
	TArrayIterator<ZSoundPlayerChannel*> ChannelsBegin();
	TArrayIterator<ZSoundPlayerChannel*> ChannelsEnd();
	bool ChannelsEmpty() const;
};
