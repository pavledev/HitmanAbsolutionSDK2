#pragma once
#pragma warning(disable : 4005)

#include <D3D11.h>

#include "SRenderTargetViewDesc.h"

class ZRenderDevice;
class ZRenderTexture3D;

class ZRenderTargetView3D
{
public:
	SRenderTargetViewDesc m_Description;
	ZRenderTexture3D* m_pTexture;
	ID3D11RenderTargetView* m_pRTV;

	virtual ~ZRenderTargetView3D() = default;

	ZRenderTargetView3D() = default;
	ZRenderTargetView3D(const SRenderTargetViewDesc* pDescription, ZRenderTexture3D* pTexture, ZRenderDevice* pRenderDevice);
	ZRenderTexture3D* GetTexture() const;
	ID3D11RenderTargetView* GetRenderTargetView() const;
};
