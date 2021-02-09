#pragma once

#include "TRenderReferencedCountedImpl.h"
#include "IRenderTextureResource.h"
#include "ZRenderShaderResourceView.h"
#include "ZTextureMap.h"

class alignas(4) ZRenderTextureResource : public TRenderReferencedCountedImpl<IRenderTextureResource, 0>
{
public:
    TArray<ZRenderShaderResourceView*> m_SRVs;
    ZTextureMap::EInterpretAs m_eInterpretAs;
    ZTextureMap::EDimensions m_eDimensions;
    bool m_bReady;
};
