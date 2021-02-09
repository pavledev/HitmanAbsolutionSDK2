#pragma once
#pragma warning(disable : 4005)

#include <D3D11.h>
#include <DirectX\d3dx11effect.h>
#include "ZRenderShader.h"

class ZRenderEffectTechnique;
class ZRenderEffectVariableD3D11;

class alignas(4) ZRenderEffectPass
{
public:
    ID3D11SamplerState** m_ppUnpatchedSamplerState;
    ZRenderEffectTechnique* m_pTechnique;
    ID3DX11EffectPass* m_pPass;
    ID3D11ShaderReflection* m_pReflectionVS;
    ID3D11ShaderReflection* m_pReflectionGS;
    ID3D11ShaderReflection* m_pReflectionPS;
    ID3D11ShaderReflection* m_pReflectionCS;
    ID3D11ShaderReflection* m_pReflectionHS;
    ID3D11ShaderReflection* m_pReflectionDS;
    ZRenderShader m_VertexShader;
    ZRenderShader m_GeometryShader;
    ZRenderShader m_PixelShader;
    ZRenderShader m_ComputeShader;
    ZRenderShader m_HullShader;
    ZRenderShader m_DomainShader;
    ID3D11DeviceContext* m_pDeviceContext;
    char* m_pInputSignature;
    unsigned int m_nInputSignatureSize;

    virtual ~ZRenderEffectPass();
    virtual ZRenderEffectVariableD3D11* GetVariableByName(ZString*);
};
