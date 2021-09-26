#pragma once

#include "ZEntityImpl.h"
#include "ISoundEffect.h"

class ZSoundEffect : public ZEntityImpl, public ISoundEffect
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	struct SEffectInstance
	{
		FMOD::DSP* m_pDSP;
		ISoundEffectAttachable* m_pEffectAttachable;
		void* m_pOwner;
		bool m_bIsSilent;
		ZGameTime m_LastChannelEndTime;

		SEffectInstance(const SEffectInstance& __that);
		SEffectInstance() = default;
		SEffectInstance& operator=(const SEffectInstance& __that);
	};

	TArray<SEffectInstance> m_pEffectInstances;
	int m_lType;
	bool m_bActive;
	float m_fMuteTime;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundEffect() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	virtual void UpdateAll(FMOD::DSP* pDSP);
	virtual FMOD::DSP* CreateCustomDSP();

	FMOD::DSP* CreateEffectInstance(ISoundEffectAttachable* pSoundEffectAttachable, void* pOwner) override;
	void DestroyEffectInstance(void* pOwner) override;
	void UpdateAll() override;
	void SetActive(const bool bActive) override;
	void Update(ZGameTime currentTime, bool bForce) override;

	ZSoundEffect() = default;
	static void RegisterType();
	ZSoundEffect(ZComponentCreateInfo& info);
	void OnActiveChanged();
	void OnMuteTimeChanged();
	void OnActive(bool bActive);
};
