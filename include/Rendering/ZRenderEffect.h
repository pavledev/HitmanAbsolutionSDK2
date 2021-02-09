#pragma once

#include "TRenderReferencedCountedImpl.h"
#include "RenderReferencedCountedBaseStub.h"
#include "ZString.h"
#include "./DirectX/d3dx11effect.h"
#include "THashMap.h"
#include "ZRenderDevice.h"
#include "TDefaultHashMapPolicy.h"

class ZRenderEffectConstantBufferD3D11;
class ZRenderEffectTechnique;
class ZRenderEffectVariableD3D11;

class ZRenderEffect : public TRenderReferencedCountedImpl<RenderReferencedCountedBaseStub, 0>
{
public:
    ZString m_sName;
    ID3DX11Effect* m_pEffect;
    ZRenderDevice* m_pRenderDevice;
    THashMap<ZString, ZRenderEffectTechnique*, TDefaultHashMapPolicy<ZString, ZRenderEffectTechnique*>> m_Techniques;
    THashMap<ZString, ZRenderEffectVariableD3D11*, TDefaultHashMapPolicy<ZString, ZRenderEffectVariableD3D11*>> m_Variables;
    THashMap<ZString, ZRenderEffectConstantBufferD3D11*, TDefaultHashMapPolicy<ZString, ZRenderEffectConstantBufferD3D11*>> m_ConstantBuffers;
};
