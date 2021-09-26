#pragma once

#include <./DirectX/d3dx11effect.h>

#include "TRenderReferencedCountedImpl.h"
#include "ZString.h"
#include "THashMap.h"

class ZRenderEffectConstantBufferD3D11;
class ZRenderEffectTechnique;
class ZRenderEffectVariableD3D11;
class RenderReferencedCountedBaseStub;
class ZRenderDevice;
class ZRenderShader;
template <class A, class B> class TDefaultHashMapPolicy;

class ZRenderEffect : public TRenderReferencedCountedImpl<RenderReferencedCountedBaseStub, 0>
{
public:
	ZString m_sName;
	ID3DX11Effect* m_pEffect;
	ZRenderDevice* m_pRenderDevice;
	THashMap<ZString, ZRenderEffectTechnique*, TDefaultHashMapPolicy<ZString, ZRenderEffectTechnique*>> m_Techniques;
	THashMap<ZString, ZRenderEffectVariableD3D11*, TDefaultHashMapPolicy<ZString, ZRenderEffectVariableD3D11*>> m_Variables;
	THashMap<ZString, ZRenderEffectConstantBufferD3D11*, TDefaultHashMapPolicy<ZString, ZRenderEffectConstantBufferD3D11*>> m_ConstantBuffers;

	~ZRenderEffect() override = default;
	virtual ZRenderEffectTechnique* GetTechniqueByName(const ZString& sName);
	virtual ZRenderEffectVariableD3D11* GetVariableByName(const ZString& sName);

	ZRenderEffect() = default;
	ZRenderEffect(const ZString& sName, ID3DX11Effect* pEffect, ZRenderDevice* pRenderDevice);
	ID3DX11Effect* GetD3DEffect() const;
	ZRenderDevice* GetRenderDevice() const;
	ZRenderShader* GetVertexShader(const ZString& name, unsigned int nPass);
	ZRenderShader* GetGeometryShader(const ZString& name, unsigned int nPass);
	ZRenderShader* GetFragmentShader(const ZString& name, unsigned int nPass);
	ZRenderShader* GetHullShader(const ZString& name, unsigned int nPass);
	ZRenderShader* GetDomainShader(const ZString& name, unsigned int nPass);
};
