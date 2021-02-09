#pragma once
#pragma warning(disable : 4005)

//#include "ZRenderDevice.h"
#include <D3D11.h>
#include "ZRenderTargetView.h"
#include "SRenderDestinationDesc.h"

class ZRenderDevice;

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

    virtual ~ZRenderSwapChain();
    virtual void SetDisableStereoscopic(bool);
};
