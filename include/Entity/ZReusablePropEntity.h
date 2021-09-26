#pragma once

#include "ZEntityImpl.h"
#include "IReusableProp.h"

class ZComponentCreateInfo;

class ZReusablePropEntity : public ZEntityImpl, public IReusableProp
{
public:
	bool m_bUsedOnce;

	~ZReusablePropEntity() override = default;
	void Init() override;

	void UseOnce() override;
	void ResetUsedFlag() override;
	bool IsUsed() const override;

	ZReusablePropEntity() = default;
	static void RegisterType();
	ZReusablePropEntity(ZComponentCreateInfo& info);
};
