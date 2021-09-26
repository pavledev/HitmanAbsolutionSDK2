#pragma once

#include "SRenderDepthStencilViewDesc.h"
#include "d3d11.h"

class ZRenderDevice;
class ZRenderTexture2D;

class ZRenderDepthStencilView
{
public:
	SRenderDepthStencilViewDesc m_Description;
	ZRenderTexture2D* m_pTexture;
	ID3D11DepthStencilView* m_pDSV;

	virtual ~ZRenderDepthStencilView() = default;

	ZRenderDepthStencilView() = default;
	ZRenderDepthStencilView(const SRenderDepthStencilViewDesc* pDescription, ZRenderTexture2D* pTexture, ZRenderDevice* pRenderDevice);
	ZRenderTexture2D* GetTexture() const;
	void GetDesc(SRenderDepthStencilViewDesc* pDescription);
	ID3D11DepthStencilView* GetDepthStencilView() const;
};
