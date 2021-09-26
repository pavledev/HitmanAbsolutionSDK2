#pragma once

#include "ISoundEffectAttachable.h"
#include "ZSoundBlendEvent.h"
#include "ZSoundBlendTrack.h"

class ZSoundBlendTrackInstance : public ISoundEffectAttachable
{
public:
	ZSoundBlendEvent* m_pEventOwner;
	FMOD::ChannelGroup* m_pChannelGroup;
	ZSoundBlendItemManager m_ItemManager;
	TList<ZSoundBlendItemInstance> m_pPlayingItemInstances;
	TEntityRef<ZSoundBlendTrack> m_pTrack;
	TArray<FMOD::DSP*> m_aEffects;
	int m_nTrackIndex;
	bool m_bDisposable;

	~ZSoundBlendTrackInstance() override = default;
	void AttachEffectInstance(FMOD::DSP* pEffect, void* pOwner) override;
	bool IsSilent() const override;

	ZSoundBlendTrackInstance() = default;
	ZSoundBlendTrackInstance(ZSoundBlendEvent* pOwner, TEntityRef<ZSoundBlendTrack> pTrack);
	void SetPosition(const float4& vPosition);
	void Update(float fDeltaTime);
	void SetMuteState(bool bIsMuted);
	float GetAudibility();
	FMOD::ChannelGroup* GetChannelGroup();
	TEntityRef<ZSoundBlendItemSubtrack> GetItemSubtrack();
	void StartMarkedItems(const SItemPair& startItems);
	void ModifyChannelProps(float fPrimarySource);
	void ForgetOwner();
	void StopItemInstances(const SItemPair& stopItems, bool bForceStop);
	void StopAllItemInstances();
	ZSoundBlendItemManager* GetItemManagerPtr();
};
