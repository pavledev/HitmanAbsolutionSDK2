#pragma once

#include "ZString.h"
#include "ZRenderEffect.h"

class ZRenderEffectVariableD3D11
{
public:
    ZString m_sName;
    ZRenderEffect* m_pEffect;
    ID3DX11EffectVariable* m_pVariable;

    virtual ~ZRenderEffectVariableD3D11();
    virtual ZString* GetName();
};
