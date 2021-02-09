#pragma once

#include "ZString.h"
#include "ZRenderEffect.h"

class ZRenderEffectTechnique
{
public:
    ZString m_sName;
    ZRenderEffect* m_pEffect;
    ID3DX11EffectTechnique* m_pTechnique;
    TArray<ZRenderEffectPass*> m_Passes;

    virtual ~ZRenderEffectTechnique();
    virtual ZRenderEffectPass* GetPassByIndex(unsigned int);
    virtual ZRenderEffect* GetEffect();
};
