#pragma once

#include "ECCEmitterEffect.h"
#include "ECCDecalEffect.h"

struct SCloseCombatEffect
{
	ECCEmitterEffect m_eEmitterEffect;
	ECCDecalEffect m_eDecalEffect;
	bool m_bHitman;
	float m_fFraction;

	SCloseCombatEffect() = default;
	~SCloseCombatEffect() = default;
};
