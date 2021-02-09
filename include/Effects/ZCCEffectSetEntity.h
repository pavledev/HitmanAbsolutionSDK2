#pragma once

#include "ZEntityImpl.h"
#include "ECCDecalEffect.h"
#include "ECCEmitterEffect.h"

class ZCCEffectSetEntity : public ZEntityImpl
{
public:
    ECCDecalEffect m_eDecalEffect;
    ECCEmitterEffect m_eEmitterEffect;
    unsigned int m_nEvent;
};
