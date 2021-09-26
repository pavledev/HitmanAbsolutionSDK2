#pragma once

#include "ZRenderContext.h"

struct __declspec(novtable) SEffectParameters
{
	bool m_bValid;

	virtual ~SEffectParameters() = default;
	virtual void Update(ZRenderEffect* renderEffect) = 0;

	SEffectParameters() = default;
};
