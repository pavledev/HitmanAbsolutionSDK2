#pragma once
#pragma warning(disable : 4005)

#include <D3D11.h>

#include "ZMutex.h"

class ZRenderDevice;
class ZRenderShaderResourceView;
class ZRenderTargetView;
class ZRenderTexture2D;
struct SRenderDestinationDesc;

class ZRenderSwapChain
{
public:
	bool m_bIsExclusiveFullscreen;
	bool m_bCustomUpscaling;
	bool m_bIsStereoscopic;
	ZRenderDevice* m_pRenderDevice;
	IDXGISwapChain* m_pSwapChain;
	ZRenderTexture2D* m_pVirtualBackBufferTexture;
	ZRenderShaderResourceView* m_pVirtualBackBufferSRV;
	ZRenderTargetView* m_pVirtualBackBufferRTV;
	ZRenderTexture2D* m_pBackBufferTexture;
	ZRenderTargetView* m_pBackBufferRTV;
	ZRenderTexture2D* m_pGammaCorrectionBlitTexture;
	ZRenderShaderResourceView* m_pGammaCorrectionBlitSRV;
	ZRenderTexture2D* m_pStereoRenderTexture;
	int m_nDisableStereoscopic;
	SRenderDestinationDesc* m_pDescription;
	ZMutex m_mutex;

	virtual ~ZRenderSwapChain() = default;
	virtual void SetDisableStereoscopic(bool bDisable);

	ZRenderSwapChain() = default;
	ZRenderSwapChain(const SRenderDestinationDesc* pDescription, ZRenderDevice* pRenderDevice);
	ZRenderTargetView* GetBackBufferRTV();
	ZRenderTexture2D* GetGammaCorrectionBlitTexture();
	IDXGISwapChain* GetSwapChain() const;
	ZRenderTargetView* GetBackBufferRTVForUpscale();
	ZRenderShaderResourceView* GetVirtualBackBufferSRVForUpscale();
	void StereoBlit(bool bLeftEye);
	bool IsStereoscopicEnabled();
	const SRenderDestinationDesc* GetDescription() const;
	void ReleaseTextures();
	void SetupTextures();
	void Resize(const SRenderDestinationDesc* pDescription);
	void Recreate(const SRenderDestinationDesc* pDescription);
	void CreateSwapchain(const SRenderDestinationDesc* pDescription);
	void DestroySwapchain();
	void WaitForGPUIdle();
};
