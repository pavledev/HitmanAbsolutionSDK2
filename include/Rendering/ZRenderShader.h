#pragma once

#include "SRenderConstBufferDesc.h"
#include "d3d11.h"

class ZRenderEffectPass;

class ZRenderShader
{
public:
	SRenderConstBufferDesc ConstBufferDesc;

	union 
	{
		ID3D11PixelShader* pPixelShader;
		ID3D11GeometryShader* pGeometryShader;
		ID3D11VertexShader* pVertexShader;
		ID3D11ComputeShader* pComputeShader;
		ID3D11HullShader* pHullShader;
		ID3D11DomainShader* pDomainShader;
	};

	unsigned char* m_pInputSignature;
	unsigned int m_nInputSignatureSize;
	unsigned int nGlobalOffset;
	unsigned int nLastTextureStream;
	ZRenderEffectPass* pPass;

	ZRenderShader() = default;
	const SRenderConstBufferDesc& GetConstBufferDesc();
	~ZRenderShader() = default;
};
