#pragma once
#pragma warning(disable : 4005)

#include "SRenderDepthStencilStateDesc.h"
#include "d3d11.h"

class ZRenderDevice;

class ZRenderDepthStencilState
{
public:
	SRenderDepthStencilStateDesc m_Description;
	ID3D11DepthStencilState* m_pDepthStencilState;

	virtual ~ZRenderDepthStencilState() = default;

	ZRenderDepthStencilState() = default;
	ZRenderDepthStencilState(const SRenderDepthStencilStateDesc* pDescription, ZRenderDevice* pRenderDevice);
	ID3D11DepthStencilState* GetDepthStencilState() const;
};
