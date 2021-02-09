#pragma once

#include "ZRenderContext.h"

class alignas(4) SEffectParameters
{
public:
    bool m_bValid;

    virtual ~SEffectParameters();
    virtual void Update(ZRenderEffect*);
};