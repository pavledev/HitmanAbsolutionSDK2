#pragma once
#pragma warning(disable : 4005)

#include "TRenderReferencedCountedImpl.h"
#include "RenderReferencedCountedBaseStub.h"
#include "SRenderUnorderedAccessViewDesc.h"
#include "IRenderResource.h"
#include <D3D11.h>

class ZRenderUnorderedAccessView : TRenderReferencedCountedImpl<RenderReferencedCountedBaseStub, 0>
{
    SRenderUnorderedAccessViewDesc m_Description;
    IRenderResource* m_pResource;
    ID3D11UnorderedAccessView* m_pUAV;
};
