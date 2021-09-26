#pragma once

#include "ZEntityImpl.h"
#include "TArray.h"

class ZSoundBlendSubtrackBase : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TArray<ZEntityRef> m_ParameterCurves;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundBlendSubtrackBase() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZSoundBlendSubtrackBase() = default;
	static void RegisterType();
	ZSoundBlendSubtrackBase(ZComponentCreateInfo& Info);
};
