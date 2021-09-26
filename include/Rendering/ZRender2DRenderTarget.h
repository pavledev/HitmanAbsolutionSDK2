#pragma once

#include "ERenderFormat.h"

class ZRenderDepthStencilView;
class ZRenderShaderResourceView;
class ZRenderTargetView;
class ZRenderTexture2D;
class ZString;

class ZRender2DRenderTarget
{
public:
	unsigned int m_nWidth;
	unsigned int m_nHeight;
	ZRenderTexture2D* m_pTexture;
	ZRenderTargetView* m_pRTV;
	ZRenderShaderResourceView* m_pSRV;
	ZRenderTexture2D* m_pDepthTexture;
	ZRenderDepthStencilView* m_pDSV;

	ZRender2DRenderTarget() = default;
	ZRender2DRenderTarget(unsigned int nWidth, unsigned int nHeight, ERenderFormat nRenderFormat, bool bCreateDepthTexture, ZString sName);
	~ZRender2DRenderTarget() = default;
	ZRenderTexture2D* GetRenderTarget2D() const;
	ZRenderTargetView* GetRenderTargetView() const;
	ZRenderShaderResourceView* GetShaderResourceView() const;
	void Init();
	void CopyToTarget(ZRender2DRenderTarget* pTarget);
};
