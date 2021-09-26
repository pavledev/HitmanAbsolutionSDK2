#pragma once

#include "ECCDecalEffect.h"
#include "ECCEmitterEffect.h"

struct SCCEffectSet
{
	ECCDecalEffect m_eDecalEffect;
	ECCEmitterEffect m_eEmitterEffect;

	SCCEffectSet() = default;
	~SCCEffectSet() = default;
};
