#pragma once

class ZRenderShaderResourceView;
class ZRenderTargetView;
class ZRenderTexture2D;

struct SRenderTexture2DAccess
{
	ZRenderShaderResourceView* m_pSRV;
	ZRenderTargetView* m_pRTV;
	ZRenderTexture2D* m_pTexture;

	SRenderTexture2DAccess() = default;
	~SRenderTexture2DAccess() = default;
};
