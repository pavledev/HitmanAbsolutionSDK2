#pragma once

#include "ECCEmitterEffect.h"
#include "ECCDecalEffect.h"

class SCloseCombatEffect
{
public:
    ECCEmitterEffect m_eEmitterEffect;
    ECCDecalEffect m_eDecalEffect;
    bool m_bHitman;
    float m_fFraction;
};
