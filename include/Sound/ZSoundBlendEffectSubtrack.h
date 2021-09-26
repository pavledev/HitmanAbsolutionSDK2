#pragma once

#include "ZSoundBlendSubtrackBase.h"
#include "TEntityRef.h"
#include "ZSoundEffect.h"

class ZSoundBlendEffectSubtrack : public ZSoundBlendSubtrackBase
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<ZSoundEffect> m_Effect;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundBlendEffectSubtrack() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZSoundBlendEffectSubtrack() = default;
	static void RegisterType();
	ZSoundBlendEffectSubtrack(ZComponentCreateInfo& Info);
};
