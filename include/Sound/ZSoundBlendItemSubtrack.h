#pragma once

#include "ZSoundBlendSubtrackBase.h"

class ZSoundBlendItemSubtrack : public ZSoundBlendSubtrackBase
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TArray<ZEntityRef> m_Items;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundBlendItemSubtrack() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZSoundBlendItemSubtrack() = default;
	static void RegisterType();
	ZSoundBlendItemSubtrack(ZComponentCreateInfo& Info);
};
