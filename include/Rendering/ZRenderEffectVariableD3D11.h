#pragma once

#include "ZString.h"
#include "ZRenderEffect.h"

class ZRenderEffectVariableD3D11
{
public:
	ZString m_sName;
	ZRenderEffect* m_pEffect;
	ID3DX11EffectVariable* m_pVariable;

	virtual ~ZRenderEffectVariableD3D11() = default;
	virtual const ZString& GetName() const;

	ZRenderEffectVariableD3D11() = default;
	ZRenderEffectVariableD3D11(const ZString& sName, ZRenderEffect* pEffect, ID3DX11EffectVariable* pVariable);
	ID3DX11EffectVariable* GetVariable() const;
};
