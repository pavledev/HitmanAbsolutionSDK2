#pragma once
#pragma warning(disable : 4005)

#include <D3D11.h>

#include "SRenderTargetViewDesc.h"

class ZRenderDevice;
class ZRenderTexture2D;

class ZRenderTargetView
{
public:
	SRenderTargetViewDesc m_Description;
	ZRenderTexture2D* m_pTexture;
	ID3D11RenderTargetView* m_pRTV;

	virtual ~ZRenderTargetView() = default;

	ZRenderTargetView() = default;
	ZRenderTargetView(const SRenderTargetViewDesc* pDescription, ZRenderTexture2D* pTexture, ZRenderDevice* pRenderDevice);
	ZRenderTexture2D* GetTexture() const;
	void GetDesc(SRenderTargetViewDesc* pDescription);
	ID3D11RenderTargetView* GetRenderTargetView() const;
};
