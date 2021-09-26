#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZSoundBlendItemSubtrack.h"
#include "ZSoundBlendEffectSubtrack.h"
#include "ISoundBlendContainer.h"

class ZSoundBlendTrackInstance;

class ZSoundBlendTrack : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	unsigned int m_nPrimarySourceID;
	TEntityRef<ZSoundBlendItemSubtrack> m_ItemSubtrack;
	TArray<TEntityRef<ZSoundBlendEffectSubtrack>> m_EffectSubtracks;
	ISoundBlendContainer* m_pOwner;
	int m_nPrimarySourceIndex;
	bool m_bIsMuted;
	TArray<ZSoundBlendTrackInstance*> m_TrackInstances;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundBlendTrack() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZSoundBlendTrack() = default;
	static void RegisterType();
	ZSoundBlendTrack(ZComponentCreateInfo& Info);
	void SetMuteState(bool bIsMuted);
	void SetOwner(ISoundBlendContainer* pOwner);
	int GetPrimarySourceIndex();
	unsigned int GetPrimarySourceID();
	void RegisterTrackInstance(ZSoundBlendTrackInstance* pInstance);
	void UnregisterTrackInstance(ZSoundBlendTrackInstance* pInstance);
	void OnPrimarySourceIDChanged();
};
