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

	virtual ~ZRenderEffectTechnique() = default;
	virtual ZRenderEffectPass* GetPassByIndex(unsigned int nIndex);
	virtual ZRenderEffect* GetEffect();

	ZRenderEffectTechnique() = default;
	ZRenderEffectTechnique(const ZString& sName, ZRenderEffect* pEffect, ID3DX11EffectTechnique* pTechnique);
	unsigned int GetNumPasses();
	ID3DX11EffectTechnique* GetTechnique() const;
};
