#pragma once

#include "ISoundPlayerChannelOwner.h"
#include "ZSoundBlendTrackInstance.h"

class ZSoundBlendItemInstance : public ISoundPlayerChannelOwner
{
public:
	TEntityRef<ZSoundBlendItem> m_pSoundItem;
	ZSoundPlayerChannel* m_pChannel;
	int m_nItemIndex;
	ZSoundBlendItemManager* m_pItemManager;
	ZSoundBlendTrackInstance* m_pTrackInstance;
	ZSoundBlendEvent* m_pEventOwner;
	ZSoundSelector m_selector;
	float m_fRetriggerTimeUnscaled;
	float m_fRetriggerTimeCounter;
	bool m_bIsRetriggerable;
	float m_fCrossFadeCoeff;
	ESoundFadeMode m_eFadeMode;
	float m_fFadeVolumeMultiplier;
	float m_fFadeVelocity;
	int m_nPlayingChannels;
	bool m_bDisposable;
	bool m_bProperlyInitialized;

	~ZSoundBlendItemInstance() override = default;
	void ChannelFailedCallback(ZSoundPlayerChannel* pChannel) override;
	void ChannelPlayCallback(int nChannel, ZSoundPlayerChannel* pChannel) override;
	void ChannelOwnerCallback(FMOD_CHANNEL_CALLBACKTYPE type, void* commanddata1, void* commanddata2, ZSoundPlayerChannel* pChannel) override;

	ZSoundBlendItemInstance(const ZSoundBlendItemInstance& __that);
	ZSoundBlendItemInstance(const TEntityRef<ZSoundBlendItem>& item, int nItemIndex, ZSoundBlendTrackInstance* pInstance, ZSoundBlendEvent* pEvent);
	ZSoundBlendItemInstance() = default;
	float GetMinParam() const;
	float GetMaxParam() const;
	void SetCrossFadeCoeff(float fCoeff);
	float GetAudibility() const;
	void ApplyItemPropsOnChannel();
	void Play();
	void Update(float fDeltaTime);
	void Stop(bool bForceStop);
	void SetPosition(const float4& vPosition);
	void SetMuteState(bool bIsMuted);
	const TEntityRef<ZSoundBlendItem> GetItem() const;
	bool IsDisposable();
	void GetCurveValues(TEntityRef<ZSoundBlendItemSubtrack> pItemSubtrack, float& fCurveAttenuation, float& fCurvePitch, float& fCurveTimeFactor);
	void Terminate();
	void SetFadeMode(const ESoundFadeMode& eFadeMode);
};
