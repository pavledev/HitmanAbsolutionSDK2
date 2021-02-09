#pragma once

#include "TRenderReferencedCountedImpl.h"
#include "IRenderDestination.h"
#include "ZRenderDevice.h"
#include "ZEvent.h"
#include "ZEventNull.h"

class alignas(4) ZRenderDestination : public TRenderReferencedCountedImpl<IRenderDestination, 0>
{
public:
    SRenderDestinationDesc m_Description;
    ZRenderDevice* m_pRenderDevice;
    ZEvent<SRenderDestinationDesc const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_ChangedHandlers;
    ZEvent<SRenderDestinationDesc const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_DeviceWillResetHandlers;
    ZEvent<SRenderDestinationDesc const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_DeviceDidResetHandlers;
    ZRenderSwapChain* m_pSwapChain;
    ZRenderTexture2D* m_pTexture;
    ZRenderTargetView* m_pRTV;
    ZRenderShaderResourceView* m_pSRV;
    TList<IRenderDestinationEntity*> m_RenderDestinationEntities;
    bool m_bHasChanged;
    bool m_bSizeChanged;
    bool m_bNeedsClear;
};
