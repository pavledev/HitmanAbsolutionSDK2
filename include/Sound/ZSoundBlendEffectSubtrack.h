#pragma once

#include "ZSoundBlendSubtrackBase.h"
#include "TEntityRef.h"
#include "ZSoundEffect.h"

class ZSoundBlendEffectSubtrack : public ZSoundBlendSubtrackBase
{
public:
    TEntityRef<ZSoundEffect> m_Effect;
};
